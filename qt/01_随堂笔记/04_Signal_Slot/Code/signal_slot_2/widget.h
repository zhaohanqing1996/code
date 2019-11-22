#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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

private slots:
    //   on_对象名_信号名();          关联死了  槽的触发条件固定了
    void on_calculateBtn_clicked();
public slots:
    void clearInput();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
