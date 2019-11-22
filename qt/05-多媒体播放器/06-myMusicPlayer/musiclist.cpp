#include "musiclist.h"
#include "ui_musiclist.h"
#include <QSettings>
#include <QCloseEvent>

musicList::musicList(QWidget *parent) : QWidget(parent), ui(new Ui::musicList)
{
    ui->setupUi(this);
    listReadSettings();              //恢复窗口位置    
    this->setWindowFlags(Qt::Tool);  //表明这是一个工具窗口
}

musicList::~musicList()
{
    delete ui;
}
void musicList::closeEvent(QCloseEvent *e)
{
    emit listClose();
    listWriteSettings();
    e->accept();         //接收事件
}

void musicList::listReadSettings()   //读取播放列表的位置,大小信息
{
    //QSettings 类提供“持久性”，平台独立的应用程序设置。意思是，程序关闭后QSettings把窗体大小，位置，用户设置的Option 保存起来，下次打开程序时再重新加载。
    QSettings settings("yafeilinux", "Phonon LIST");//  公司或组织名  应用程序名
    QPoint pos = settings.value("pos", QPoint(this->x(),this->y()+150)).toPoint();
    QSize size = settings.value("size", QSize(300,320)).toSize();
    move(pos);
    resize(size);
}

void musicList::listWriteSettings()//记录播放列表的位置,大小信息
{
    QSettings settings("yafeilinux","Phonon LIST");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

