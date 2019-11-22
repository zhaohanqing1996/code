#include "giflabel.h"

GifLabel::GifLabel(QString gif, QWidget *parent) :
    QLabel(parent)
{
    m = new QMovie(gif);
    this->setMovie(m);
}

GifLabel::~GifLabel()
{

}

void GifLabel::enterEvent(QEvent *e)
{
    m->start();
    qDebug() << "鼠标进入了";
    emit mouseIn();
}

void GifLabel::leaveEvent(QEvent *e)
{
    m->stop();
    qDebug() << "鼠标离开了";
    emit mouseLeft();
}

