#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include "run.h"
#include <iostream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit w;
    QPushButton n(QString("确定"), &w);
    QPushButton b(QString("子部件"), &w);      // QLineEdit *

    n.move(200, 0);
    w.setMinimumSize(300, 100);
    w.move(600, 300);
    w.show();



//    w.move(10, 10);
//    cout << "x: " << w.x() << endl;
//    cout << "y: " << w.y() << endl;
////    cout << "pos: " << w.pos() << endl;
////    cout << "geo: " << w.frameGeometry() << endl;

//    // C    printf   %d  %f  %c  %s
//    // C++  cout     string
//    // QT   QPoint   QRect    QColor

//    // QDebug
//    qDebug() << "pos: " << w.pos();
//    qDebug() << "geo: " << w.frameGeometry();


    return a.exec();
}

