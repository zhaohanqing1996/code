#include <QtGui/QApplication>
#include "player.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(
            QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(
            QTextCodec::codecForLocale());
    Player w;
    w.show();

    return a.exec();
}
