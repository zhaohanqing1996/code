#include "clientthread.h"

ClientThread::ClientThread(QTcpSocket *client, QSqlDatabase db, QObject *parent)
    : QThread(parent)
{
   clientSocket = client;
   sql = db;
   connect(clientSocket,SIGNAL(readyRead()),this,SLOT(readMsg()));
}

void ClientThread::readMsg()
{
    QDataStream in(clientSocket);
    QString name;
    QString passwd;
    in.setVersion(QDataStream::Qt_5_5);
    in >> name;
    in >> passwd;
    QSqlQuery query(sql);
    QString cmd = QString("select * from userInfo where name='%1' AND passwd='%2'").arg(name).arg(passwd);
    QString res;
    query.exec(cmd);
    if(query.next() && query.isValid())
    {
        res = "Yes";
        qDebug() << "Yes";
    }
    else
    {
        res = "No";
        qDebug() << "No";
    }
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << res;
    clientSocket->write(block);
}

void ClientThread::run()
{

    this->exec();
}

