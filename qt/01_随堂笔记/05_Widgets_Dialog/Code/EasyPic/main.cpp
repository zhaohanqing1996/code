#include "easypic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EasyPic w;
    w.show();

    return a.exec();
}
