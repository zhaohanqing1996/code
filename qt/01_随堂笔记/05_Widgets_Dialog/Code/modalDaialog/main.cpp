#include <QApplication>
#include "mainwidget.h"
#include "logindialog.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog d;

    if(d.exec() == QDialog::Rejected)
    {
        return 0;
    }
    MainWidget w;
    w.setWindowTitle("主界面1");
    w.show();
    return a.exec();        // 事件循环
}
