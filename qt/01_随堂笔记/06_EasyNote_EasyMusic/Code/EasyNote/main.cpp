#include "easynote.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EasyNote w;
    w.show();

    return a.exec();
}
