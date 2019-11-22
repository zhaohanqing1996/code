#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QButtonGroup *gender_Group;   //性别选择组
    QButtonGroup *marriage_Group; //婚姻状况选择组
private slots:
        void on_pushButton_ok_clicked();
        void gender_Group_slots(int id); //槽函数
        void marriage_Group_slots(int id);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
