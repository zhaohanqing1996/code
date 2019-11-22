#ifndef EASYCALCULATE_H
#define EASYCALCULATE_H

#include <QWidget>

namespace Ui {
class EasyCalculate;
}

class EasyCalculate : public QWidget
{
    Q_OBJECT

public:
    explicit EasyCalculate(QWidget *parent = 0);
    ~EasyCalculate();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_clearOneBtn_clicked();

    void on_clearAllBtn_clicked();

private:
    Ui::EasyCalculate *ui;
};

#endif // EASYCALCULATE_H
