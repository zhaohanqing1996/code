#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFont>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void setLabelFontFamily(QFont p);
    void setLabelPointSize(int v);
private:
    Ui::Widget *ui;
    QFont f;
};

#endif // WIDGET_H
