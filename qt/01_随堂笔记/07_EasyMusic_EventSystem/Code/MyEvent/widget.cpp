#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    me = new MyLineEdit(this);

    me->move(100, 100);

    first = new GifLabel("C:/Users/huxings/Desktop/学习/qt素材/gif动态图/1.gif");
    second = new GifLabel("C:/Users/huxings/Desktop/学习/qt素材/gif动态图/2.gif");
    third = new GifLabel("C:/Users/huxings/Desktop/学习/qt素材/gif动态图/3.gif");

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(first);
    layout->addWidget(second);
    layout->addWidget(third);

    QVBoxLayout * mainlayout = new QVBoxLayout(this);
    mainlayout->addWidget(me);
    mainlayout->addLayout(layout);

    connect(me,SIGNAL(sb(int)),this,SLOT(getSb(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "Widget 按键按下事件处理函数";


}

void Widget::getSb(int n)
{
    qDebug() << "n = " << n;
}
