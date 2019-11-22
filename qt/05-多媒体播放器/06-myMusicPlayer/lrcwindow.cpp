#include "lrcwindow.h"
#include <QMouseEvent>
#include <QMenu>
#include <QTimer>
#include <QDebug>
#include <QPainter>
lrcWindow::lrcWindow(QWidget *parent): QLabel(parent)
{
    //���ô�������
    this->setWindowFlags(Qt::SubWindow |Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
    this->resize(1024,60);
    this->setText(tr("Music ..."));
    this->setAttribute(Qt::WA_TranslucentBackground);//����͸��
    this->setCursor(Qt::OpenHandCursor);             //���������״

    exit = new QAction(tr("����(&D)"),this);          //���һ������
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

void lrcWindow::contextMenuEvent(QContextMenuEvent *ev)//��������Ĳ˵��¼�
{
    QMenu menu;
    menu.addAction(exit);
    menu.exec(ev->globalPos());
    QLabel::contextMenuEvent(ev);
}

void lrcWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);    //����һ������
    //painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    //ʹ�ø��д������ʵ�ַ���ݣ�ʹ�����ʾ��Ư�������ǻ���������CPUռ����
    QFont font(tr("Times New Roman"),30,QFont::Bold);
    painter.setFont(font);
    QLinearGradient lg(0,20,0,50);    //����һ�����Խ���
    lg.setColorAt(0,QColor(0,170,255,255));
    lg.setColorAt(0.2,QColor(61,214,191,250));
    lg.setColorAt(0.5,QColor(85,255,255,255));
    lg.setColorAt(0.8,QColor(61,214,191,250));
    lg.setColorAt(1,QColor(0,170,255,255));
    painter.setBrush(lg);             //ʹ�������Խ���
    painter.setPen(Qt::NoPen);        //��ʹ��ϵͳ�ṩ�Ļ���
    QPainterPath textPath;            //����һ�����ʵĹ켣
    textPath.addText(0,50,font,text());
    painter.drawPath(textPath);       //�ѻ��ʵĹ켣Ӧ�õ�������ȥ
    length = textPath.currentPosition().x();
    painter.setPen(Qt::yellow);       //���û�����ɫ
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

