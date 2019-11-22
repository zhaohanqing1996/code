#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mp = new QMediaPlayer(this);
    // 指定播放源   （播放什么文件）
    mp->setMedia(QMediaContent(QUrl(QString("C:/Users/huxings/Desktop/学习/qt素材/QT资源文件/music/林俊杰 - 一千年以后.mp3"))));
    mp->play();
}

Widget::~Widget()
{
    delete ui;
}
