#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpServer>   // 监听套接字
#include <QTcpSocket>   // 通信套接字
#include <QHostAddress>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>

struct StdInfo
{
    QString name;
    int age;
    QString sex;
    double high;
};

namespace Ui {
class Server;
}

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

public slots:
    void sendMessage();

private:
    Ui::Server *ui;

    QTcpServer * listenSocket;

};

//  in << msg;
// QDataStream << StdInfo

void operator <<(QDataStream & ds, StdInfo &d);

#endif // SERVER_H
