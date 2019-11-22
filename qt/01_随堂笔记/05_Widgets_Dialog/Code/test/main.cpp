#include <QCoreApplication>
#include <QList>
#include <QLinkedList>
#include <QLinkedListIterator>
#include <QListIterator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<int> link;
    link << 12 << 45 << 54;

    QLinkedListIterator<int> i(link);
    for(;i.hasNext();)
    {
        qDebug() << i.next();
    }
    return a.exec();
}

