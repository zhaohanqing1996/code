#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    qDebug()<<"QT调试信息输出";
    int data_int=8888;
    qDebug()<<data_int;
    float data_float=123.888;
    qDebug()<<data_float;

    return a.exec();
}
