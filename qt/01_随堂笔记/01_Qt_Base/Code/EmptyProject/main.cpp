#include <QApplication>
#include "hello.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Hello w;

    w.setWindowTitle("测试程序");
    w.show();
    return a.exec();
}


