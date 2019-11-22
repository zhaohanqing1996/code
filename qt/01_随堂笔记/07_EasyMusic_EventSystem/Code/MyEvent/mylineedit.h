#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit MyLineEdit(QWidget *parent = 0);
    ~MyLineEdit();

protected:
    //   事件处理函数     按键事件（event根据事件的类型分派给对应的处理函数进行处理）
    //     按键按下
    void keyPressEvent(QKeyEvent *e);

    void mousePressEvent(QMouseEvent *e);

signals:
    void sb(int n);
};

#endif // MYLINEEDIT_H
