#include <QtGui/QApplication>
#include "widget.h"
#include "settime_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    Widget w;
    w.show();
//	MyHttp http;
    return a.exec();
}
