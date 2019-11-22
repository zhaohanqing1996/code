#include "easymusic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EasyMusic w;
    w.show();

    return a.exec();
}
