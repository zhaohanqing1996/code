#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include "mylineedit.h"
#include "giflabel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void getSb(int n);

private:
    Ui::Widget *ui;


    MyLineEdit * me;

    GifLabel * first;
    GifLabel * second;
    GifLabel * third;
};

#endif // WIDGET_H
