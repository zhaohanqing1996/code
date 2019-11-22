#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit(parent)
{

}

MyLineEdit::~MyLineEdit()
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "MyLineEdit 键盘按下事件处理函数";
    switch(e->key())
    {
    case Qt::Key_A:  move(this->x() - 10, y()); break;
    case Qt::Key_D:  move(this->x() + 10, y()); break;
    case Qt::Key_W:  move(x(), this->y() - 10); break;
    case Qt::Key_S:  move(x(), this->y() + 10); break;
    default:
        QLineEdit::keyPressEvent(e);
    }
    // 使用基类的默认处理方式

    e->ignore();    // 让父部件的事件处理函数来处理
}

void MyLineEdit::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug() << "左键按下了";
        emit sb(80);
    }
}

