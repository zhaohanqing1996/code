#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QLabel *label =new QLabel("Hello Qt!");
//    label->setGeometry(400,100,100,20);
//    label->show();

    return a.exec();
}
