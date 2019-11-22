#include "widget.h"
#include "ui_widget.h"

QStringList fileNames;          /* 存放*.mp3 */
static int i = 0;               /* 表示第i首歌 */
static int step = 0;            /* 存放歌曲进度 */
static bool ifPause = false;    /* 表示是否按过暂停按钮 */
static bool ifPress = true;     /* 表示声音按钮是否按下 */

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::WidgetClass)
{
    ui->setupUi(this);

    timer = new QTimer;                 /* 初始化定时器 */
    connect(timer, SIGNAL(timeout()), this, SLOT(process_move()));

    ui->btn_play->setEnabled(true);     /* 初始时，播放按钮可用 */
    ui->btn_pause->setEnabled(false);   /* 初始时，暂停按钮变灰，不可用 */
    ui->btn_stop->setEnabled(false);    /* 初始时，停止按钮不可用 */
}

Widget::~Widget()
{
    delete ui;
}

/********************************播放函数********************************/
void Widget::mp3_play()                 /* 歌曲进度 */
{
    char buf[64] = {'\0'};
    if(fileNames.size() > 0)            /* 如果文件列表不为空 */
        sprintf(buf, "madplay %s &", fileNames.at(i).toLocal8Bit().constData());
    system(buf);                        /* 播放这首歌 */
}
/**********************************************************************/


/******************************进度处理函数******************************/
void Widget::process_move()             /* 歌曲进度 */
{
    step ++;                            /* 单步向后 */
    ui->process_bar->setValue(step);    /* 设置进度 */
}
/**********************************************************************/


/******************************打开处理函数******************************/
void Widget::on_btn_open_clicked()      /* 打开按钮 */
{
    /* 打开*.MP3文件，保存在fileNames里面 */
    fileNames = QFileDialog::getOpenFileNames(this, "mp3", "/home/mp3", "MP3 FILE(*.mp3)");
}
/**********************************************************************/


/******************************播放处理函数******************************/
void Widget::on_btn_play_clicked()		/* 点击开始播放 */
{
    ui->btn_play->setEnabled(false);	/* 播放按钮不可用 */
    ui->btn_pause->setEnabled(true);	/* 暂停按钮可用 */
    ui->btn_stop->setEnabled(true);		/* 停止按钮可用 */

    if(ifPause == false)				/* ifPause为false表示暂停按钮没有按过，即播放音乐 */
    {
        timer->start(1000);             /* 定时器开始工作，设置为1秒 */
        mp3_play();
    }
    else								/* ifPause为true表示暂停之前是暂停，即恢复播放 */
    {
        timer->start();
        system("killall -CONT madplay &");  /* madplay恢复播放 */
    }
}
/**********************************************************************/


/******************************暂停处理函数******************************/
void Widget::on_btn_pause_clicked()     /* 点击暂停播放按钮 */
{
    ui->btn_play->setEnabled(true);     /* 播放按钮可用 */
    ui->btn_pause->setEnabled(false);   /* 暂停按钮不可用 */
    ui->btn_stop->setEnabled(true);     /* 停止按钮可用 */

    timer->stop();                      /* 定时器暂停 */
    ifPause = true;                     /* 表示按下过暂停按钮 */
    system("killall -STOP madplay &");  /* madplay暂停播放 */
}
/**********************************************************************/


/******************************停止处理函数******************************/
void Widget::on_btn_stop_clicked()      /* 点击停止播放 */
{
    ui->btn_play->setEnabled(true);     /* 播放按钮可用 */
    ui->btn_pause->setEnabled(false);   /* 暂停按钮不可用 */
    ui->btn_stop->setEnabled(false);    /* 停止按钮不可用 */

    timer->stop();                      /* 定时器暂停 */
    ifPause = true;                     /* 表示按下过暂停按钮 */
    step = 0;                           /* 进度条清零 */
    ui->process_bar->setValue(step);    /* 设置进度条从头开始 */
    system("killall -9 madplay");       /* madplay停止播放 */
}
/**********************************************************************/


/*****************************上一曲处理函数*****************************/
void Widget::on_btn_perv_clicked()      /* 点击播放上一曲 */
{
    ui->btn_play->setEnabled(false);    /* 播放按钮不可用 */
    ui->btn_pause->setEnabled(true);    /* 暂停按钮可用 */
    ui->btn_stop->setEnabled(true);     /* 停止按钮可用 */

    step = 0;                           /* 进度条清零 */
    ui->process_bar->setValue(step);    /* 设置进度条从头开始 */
    system("killall -9 madplay");       /* 先终止音乐播放 */

    if(i == 0)                          /* 如果已经是第一首了，则再回到最后一首 */
        i = fileNames.size() - 1;
    else
        i--;                            /* 上一首 */
    mp3_play();
}
/**********************************************************************/


/*****************************下一曲处理函数*****************************/
void Widget::on_btn_next_clicked()      /* 点击播放下一曲 */
{
    ui->btn_play->setEnabled(false);    /* 播放按钮不可用 */
    ui->btn_pause->setEnabled(true);    /* 暂停按钮可用 */
    ui->btn_stop->setEnabled(true);     /* 停止按钮可用 */

    step = 0;                           /* 进度条清零 */
    ui->process_bar->setValue(step);    /* 设置进度条从头开始 */
    system("killall -9 madplay");       /* 先终止音乐播放 */

    if(i == (fileNames.size() - 1))     /* 如果已经是最后一首了，则再回到第一首 */
        i = 0;
    else
        i++;                            /* 下一首 */
    mp3_play();
}
/**********************************************************************/


/******************************声音处理函数******************************/
void Widget::on_btn_voice_clicked()     /* 声音按钮 */
{
    if(ifPress == true)                 /* 静音 */
    {
        ifPress = false;                /* 下次再按表示恢复 */
        ui->voice_bar->setValue(0);     /* 设置声音条为0 */
        on_voice_bar_valueChanged(0);   /* 调用声音控制函数 */
    }
    else                                /* 恢复声音 */
    {
        ifPress = true;                 /* 下次再按表示静音 */
        ui->voice_bar->setValue(100);   /* 设置声音条为100 */
        on_voice_bar_valueChanged(100); /* 调用声音控制函数 */
    }
}
/**********************************************************************/


/******************************声音处理函数******************************/
void Widget::on_voice_bar_valueChanged(int value)   /* 声音滑动条改变 */
{
    int fd = open("/dev/mixer", O_WRONLY);      /* 打开声音控制设备 */
    ioctl(fd, SOUND_MIXER_WRITE_VOLUME, &value);/* 向声音设备里面写入声音的值 */
    ::close(fd);                                /* 关闭声音设备文件 */
}
/**********************************************************************/
