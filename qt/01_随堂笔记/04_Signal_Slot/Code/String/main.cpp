#include <QCoreApplication>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str;

    str = QString("%2 is %1 hehe %3").arg(12).arg(12.34).arg("love");

    qDebug() << "str: " <<str;

    // 12 --> QString   "12"
    str.setNum(12);
    str.sprintf("%d", 12);
    str = QString("%1").arg(12);

    // QString --> 123
    str.toInt();
    str.toDouble();

    str = "   wo ao     skdfjds     sdfad    ";
    qDebug() << "str: " <<str;
    str = str.simplified();
    qDebug() << "str: " <<str;



    return a.exec();
}

