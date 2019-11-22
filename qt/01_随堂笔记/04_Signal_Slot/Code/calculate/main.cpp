#include "easycalculate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EasyCalculate w;
    w.show();

    return a.exec();
}
