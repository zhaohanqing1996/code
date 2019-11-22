#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QMenu>
#include <QAction>

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
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    bool event(QEvent *e);

private:
    void memberInit();

public slots:
    void flushActionSlot(QAction * s);

private:
    Ui::Widget *ui;

    QMenu * menu;
};

#endif // WIDGET_H
