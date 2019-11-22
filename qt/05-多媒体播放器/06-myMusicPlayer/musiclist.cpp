#include "musiclist.h"
#include "ui_musiclist.h"
#include <QSettings>
#include <QCloseEvent>

musicList::musicList(QWidget *parent) : QWidget(parent), ui(new Ui::musicList)
{
    ui->setupUi(this);
    listReadSettings();              //�ָ�����λ��    
    this->setWindowFlags(Qt::Tool);  //��������һ�����ߴ���
}

musicList::~musicList()
{
    delete ui;
}
void musicList::closeEvent(QCloseEvent *e)
{
    emit listClose();
    listWriteSettings();
    e->accept();         //�����¼�
}

void musicList::listReadSettings()   //��ȡ�����б��λ��,��С��Ϣ
{
    //QSettings ���ṩ���־��ԡ���ƽ̨������Ӧ�ó������á���˼�ǣ�����رպ�QSettings�Ѵ����С��λ�ã��û����õ�Option �����������´δ򿪳���ʱ�����¼��ء�
    QSettings settings("yafeilinux", "Phonon LIST");//  ��˾����֯��  Ӧ�ó�����
    QPoint pos = settings.value("pos", QPoint(this->x(),this->y()+150)).toPoint();
    QSize size = settings.value("size", QSize(300,320)).toSize();
    move(pos);
    resize(size);
}

void musicList::listWriteSettings()//��¼�����б��λ��,��С��Ϣ
{
    QSettings settings("yafeilinux","Phonon LIST");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

