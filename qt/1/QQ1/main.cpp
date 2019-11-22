
#include <QApplication>
#include "qq.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQ w;
    w.show();

    return a.exec();
}
