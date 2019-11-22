#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1.显示文本
    ui->textLabel->setText("我真的很想你，大哥哥");
    // 2.显示图片
    QPixmap map("C:/Users/huxings/Desktop/学习/qt素材/QT资源文件/picture/2.jpg");

    ui->picLabel->setPixmap(map);
    // 2.1 改变标签大小 适应图片
    ui->picLabel->resize(map.width(), map.height());
    // 2.2 缩放图片内容 适应标签大小
 //   ui->picLabel->setScaledContents(true);

    // 3.显示 gif 动态图  需要 QMovie
    m = new QMovie("C:/Users/huxings/Desktop/学习/qt素材/gif动态图/2.gif");

    ui->gifLabel->setMovie(m);
    ui->gifLabel->setScaledContents(true);

    // 4.显示数字
    ui->numLabel->setNum(123);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_playBtn_clicked()
{
    m->start();
    qDebug() << m->speed();
}

void Widget::on_stopBtn_clicked()
{
    m->stop();
}

void Widget::on_speedSlider_valueChanged(int value)
{
    m->setSpeed(value);
}
