#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void setCome(bool t);

protected:
    void paintEvent(QPaintEvent *e);

private:
    bool come;
};

#endif // WIDGET_H
