#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QtNetwork>
#include <QTcpSocket>
#include "logindialog.h"

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private:
    void memberInit();

private:
    Ui::Client *ui;

    LoginDialog * login;        // 登录对话框
    QTcpSocket * serverSocket;

};

#endif // CLIENT_H
