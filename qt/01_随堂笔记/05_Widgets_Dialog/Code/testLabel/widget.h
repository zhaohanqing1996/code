#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMovie>
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
    void on_playBtn_clicked();

    void on_stopBtn_clicked();

    void on_speedSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
    QMovie * m;
};

#endif // WIDGET_H
