#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    come = false;
}

Widget::~Widget()
{

}

void Widget::setCome(bool t)
{
    come = t;
}

void Widget::paintEvent(QPaintEvent *e)
{
    // 1.定义画家对象，用于执行绘制操作
    QPainter painter(this);

    // 2.定义一个画笔对象，设置线条的细节（颜色，粗细，样式等）
    QPen pen1;
    pen1.setColor(Qt::blue);
    pen1.setWidth(20);
    pen1.setStyle(Qt::DashDotLine);

    painter.setPen(pen1);
    painter.drawLine(100, 100, 600, 300);

    QPen pen2;
    pen2.setColor(Qt::red);
    pen2.setWidth(8);
    pen2.setStyle(Qt::SolidLine);
    painter.setPen(pen2);


    // 3.定义一个画刷对象，设置填充效果
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::DiagCrossPattern);
    painter.setBrush(brush);

    // 4.绘制图片
    painter.drawPixmap(120, 120, 220, 320, QPixmap("C:/Users/huxings/Desktop/2.jpg"));
    painter.drawRect(120, 120, 220, 320);


    if(come)
    {
        painter.drawRect(420, 120, 220, 320);
    }
}
