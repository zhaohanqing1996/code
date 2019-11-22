#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *m_button;/*定义指针*/
        /*声明槽函数*/
public slots:
        void QPushButton_released_Slots();
        void QPushButton_pressed_Slots();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
