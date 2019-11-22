#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTcpSocket>
#include <QDataStream>
#include <QSqlQuery>
#include <QDebug>

class ClientThread : public QThread
{
    Q_OBJECT

public:
    ClientThread(QTcpSocket * client, QSqlDatabase db, QObject * parent = 0);

private:
    QTcpSocket * clientSocket;

    QSqlDatabase sql;

public slots:
    void readMsg();

protected:
    void run();
};

#endif // CLIENTTHREAD_H
