#include "lrcwindow.h"
#include <QMouseEvent>
#include <QMenu>
#include <QTimer>
#include <QDebug>
#include <QPainter>
lrcWindow::lrcWindow(QWidget *parent): QLabel(parent)
{
    //设置窗口类型
    this->setWindowFlags(Qt::SubWindow |Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
    this->resize(1024,60);
    this->setText(tr("Music ..."));
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    this->setCursor(Qt::OpenHandCursor);             //设置鼠标形状

    exit = new QAction(tr("隐藏(&D)"),this);          //添加一个动作
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));

    this->move(400,400);

    lrcWidth = 0;
}

void lrcWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }   
    QLabel::mousePressEvent(event);
}

void lrcWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - dragPosition);
        e->accept();
    }
    QLabel::mouseMoveEvent(e);
}

void lrcWindow::contextMenuEvent(QContextMenuEvent *ev)//添加上下文菜单事件
{
    QMenu menu;
    menu.addAction(exit);
    menu.exec(ev->globalPos());
    QLabel::contextMenuEvent(ev);
}

void lrcWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);    //定义一个画笔
    //painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    //使用该行代码可以实现反锯齿，使歌词显示更漂亮，但是会明显增加CPU占用率
    QFont font(tr("Times New Roman"),30,QFont::Bold);
    painter.setFont(font);
    QLinearGradient lg(0,20,0,50);    //定义一个线性渐变
    lg.setColorAt(0,QColor(0,170,255,255));
    lg.setColorAt(0.2,QColor(61,214,191,250));
    lg.setColorAt(0.5,QColor(85,255,255,255));
    lg.setColorAt(0.8,QColor(61,214,191,250));
    lg.setColorAt(1,QColor(0,170,255,255));
    painter.setBrush(lg);             //使画笔线性渐变
    painter.setPen(Qt::NoPen);        //不使用系统提供的画笔
    QPainterPath textPath;            //定义一个画笔的轨迹
    textPath.addText(0,50,font,text());
    painter.drawPath(textPath);       //把画笔的轨迹应用到画笔中去
    length = textPath.currentPosition().x();
    painter.setPen(Qt::yellow);       //设置画笔颜色
    painter.drawText(0,14,lrcWidth,50,Qt::AlignLeft,text());

}

void lrcWindow::timeout()
{
    lrcWidth += length/85;
    update();
}

void lrcWindow::setLrcWidth()
{
    lrcWidth = 0;
}

