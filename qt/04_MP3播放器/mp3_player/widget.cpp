#include "widget.h"
#include "ui_widget.h"

QStringList fileNames;          /* ���*.mp3 */
static int i = 0;               /* ��ʾ��i�׸� */
static int step = 0;            /* ��Ÿ������� */
static bool ifPause = false;    /* ��ʾ�Ƿ񰴹���ͣ��ť */
static bool ifPress = true;     /* ��ʾ������ť�Ƿ��� */

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::WidgetClass)
{
    ui->setupUi(this);

    timer = new QTimer;                 /* ��ʼ����ʱ�� */
    connect(timer, SIGNAL(timeout()), this, SLOT(process_move()));

    ui->btn_play->setEnabled(true);     /* ��ʼʱ�����Ű�ť���� */
    ui->btn_pause->setEnabled(false);   /* ��ʼʱ����ͣ��ť��ң������� */
    ui->btn_stop->setEnabled(false);    /* ��ʼʱ��ֹͣ��ť������ */
}

Widget::~Widget()
{
    delete ui;
}

/********************************���ź���********************************/
void Widget::mp3_play()                 /* �������� */
{
    char buf[64] = {'\0'};
    if(fileNames.size() > 0)            /* ����ļ��б�Ϊ�� */
        sprintf(buf, "madplay %s &", fileNames.at(i).toLocal8Bit().constData());
    system(buf);                        /* �������׸� */
}
/**********************************************************************/


/******************************���ȴ�����******************************/
void Widget::process_move()             /* �������� */
{
    step ++;                            /* ������� */
    ui->process_bar->setValue(step);    /* ���ý��� */
}
/**********************************************************************/


/******************************�򿪴�����******************************/
void Widget::on_btn_open_clicked()      /* �򿪰�ť */
{
    /* ��*.MP3�ļ���������fileNames���� */
    fileNames = QFileDialog::getOpenFileNames(this, "mp3", "/home/mp3", "MP3 FILE(*.mp3)");
}
/**********************************************************************/


/******************************���Ŵ�����******************************/
void Widget::on_btn_play_clicked()		/* �����ʼ���� */
{
    ui->btn_play->setEnabled(false);	/* ���Ű�ť������ */
    ui->btn_pause->setEnabled(true);	/* ��ͣ��ť���� */
    ui->btn_stop->setEnabled(true);		/* ֹͣ��ť���� */

    if(ifPause == false)				/* ifPauseΪfalse��ʾ��ͣ��ťû�а��������������� */
    {
        timer->start(1000);             /* ��ʱ����ʼ����������Ϊ1�� */
        mp3_play();
    }
    else								/* ifPauseΪtrue��ʾ��֮ͣǰ����ͣ�����ָ����� */
    {
        timer->start();
        system("killall -CONT madplay &");  /* madplay�ָ����� */
    }
}
/**********************************************************************/


/******************************��ͣ������******************************/
void Widget::on_btn_pause_clicked()     /* �����ͣ���Ű�ť */
{
    ui->btn_play->setEnabled(true);     /* ���Ű�ť���� */
    ui->btn_pause->setEnabled(false);   /* ��ͣ��ť������ */
    ui->btn_stop->setEnabled(true);     /* ֹͣ��ť���� */

    timer->stop();                      /* ��ʱ����ͣ */
    ifPause = true;                     /* ��ʾ���¹���ͣ��ť */
    system("killall -STOP madplay &");  /* madplay��ͣ���� */
}
/**********************************************************************/


/******************************ֹͣ������******************************/
void Widget::on_btn_stop_clicked()      /* ���ֹͣ���� */
{
    ui->btn_play->setEnabled(true);     /* ���Ű�ť���� */
    ui->btn_pause->setEnabled(false);   /* ��ͣ��ť������ */
    ui->btn_stop->setEnabled(false);    /* ֹͣ��ť������ */

    timer->stop();                      /* ��ʱ����ͣ */
    ifPause = true;                     /* ��ʾ���¹���ͣ��ť */
    step = 0;                           /* ���������� */
    ui->process_bar->setValue(step);    /* ���ý�������ͷ��ʼ */
    system("killall -9 madplay");       /* madplayֹͣ���� */
}
/**********************************************************************/


/*****************************��һ��������*****************************/
void Widget::on_btn_perv_clicked()      /* ���������һ�� */
{
    ui->btn_play->setEnabled(false);    /* ���Ű�ť������ */
    ui->btn_pause->setEnabled(true);    /* ��ͣ��ť���� */
    ui->btn_stop->setEnabled(true);     /* ֹͣ��ť���� */

    step = 0;                           /* ���������� */
    ui->process_bar->setValue(step);    /* ���ý�������ͷ��ʼ */
    system("killall -9 madplay");       /* ����ֹ���ֲ��� */

    if(i == 0)                          /* ����Ѿ��ǵ�һ���ˣ����ٻص����һ�� */
        i = fileNames.size() - 1;
    else
        i--;                            /* ��һ�� */
    mp3_play();
}
/**********************************************************************/


/*****************************��һ��������*****************************/
void Widget::on_btn_next_clicked()      /* ���������һ�� */
{
    ui->btn_play->setEnabled(false);    /* ���Ű�ť������ */
    ui->btn_pause->setEnabled(true);    /* ��ͣ��ť���� */
    ui->btn_stop->setEnabled(true);     /* ֹͣ��ť���� */

    step = 0;                           /* ���������� */
    ui->process_bar->setValue(step);    /* ���ý�������ͷ��ʼ */
    system("killall -9 madplay");       /* ����ֹ���ֲ��� */

    if(i == (fileNames.size() - 1))     /* ����Ѿ������һ���ˣ����ٻص���һ�� */
        i = 0;
    else
        i++;                            /* ��һ�� */
    mp3_play();
}
/**********************************************************************/


/******************************����������******************************/
void Widget::on_btn_voice_clicked()     /* ������ť */
{
    if(ifPress == true)                 /* ���� */
    {
        ifPress = false;                /* �´��ٰ���ʾ�ָ� */
        ui->voice_bar->setValue(0);     /* ����������Ϊ0 */
        on_voice_bar_valueChanged(0);   /* �����������ƺ��� */
    }
    else                                /* �ָ����� */
    {
        ifPress = true;                 /* �´��ٰ���ʾ���� */
        ui->voice_bar->setValue(100);   /* ����������Ϊ100 */
        on_voice_bar_valueChanged(100); /* �����������ƺ��� */
    }
}
/**********************************************************************/


/******************************����������******************************/
void Widget::on_voice_bar_valueChanged(int value)   /* �����������ı� */
{
    int fd = open("/dev/mixer", O_WRONLY);      /* �����������豸 */
    ioctl(fd, SOUND_MIXER_WRITE_VOLUME, &value);/* �������豸����д��������ֵ */
    ::close(fd);                                /* �ر������豸�ļ� */
}
/**********************************************************************/
