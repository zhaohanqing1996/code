#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    cm = new QCamera();

    finder = new QCameraViewfinder[9];
    ui->windowLayout->addWidget(finder,0,0);

    finder->move(50, 50);
//    finder->resize(800, 600);

    cm->setViewfinder(finder);
    cm->setCaptureMode(QCamera::CaptureViewfinder);

    imageCapture = new QCameraImageCapture(cm);

    fileName = "IMG_20017_11_26";
    num = 1;

    cm->start();

    connect(ui->widthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(updateWidth(int)));
    connect(ui->heightSpinBox,SIGNAL(valueChanged(int)),this,SLOT(updateHeight(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_photoPushButton_clicked()
{
    cm->setCaptureMode(QCamera::CaptureStillImage);

    cm->searchAndLock();

    QString str = "C:/Users/huxings/Desktop/新建文件夹/" + fileName + "_" + QString().setNum(num);
    imageCapture->capture(str);
    num++;


    cm->unlock();

}

void Widget::updateWidth(int n)
{
    finder->resize(n, finder->height());
}

void Widget::updateHeight(int n)
{
    finder->resize(finder->width(), n);
}
