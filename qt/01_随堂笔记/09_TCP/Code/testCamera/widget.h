#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QGridLayout>

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
    void on_photoPushButton_clicked();

    void updateWidth(int n);
    void updateHeight(int n);

private:
    Ui::Widget *ui;

    QCamera * cm;
    QCameraViewfinder * finder;

    QCameraImageCapture *imageCapture;

    QString fileName;       // IMG_2017_5_20
    int num;                // 13
    //  IMG_2017_5_20_13.JPG
};

#endif // WIDGET_H
