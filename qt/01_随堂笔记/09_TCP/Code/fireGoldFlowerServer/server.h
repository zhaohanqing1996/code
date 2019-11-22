#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <qDebug>
#include <QMessageBox>

#include "clientthread.h"

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();
private:
    void sqliteInit();
    void listenSocketInit();
    void memberInit();

public slots:
    void createServerThread();

private:        // 数据库
    QSqlDatabase db;

private:        // 网络通信
    QTcpServer * listenSocket;

private:
    Ui::Server *ui;
};

#endif // SERVER_H
