#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QAbstractSocket>
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
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void on_connectBtn_clicked();

    void newConnect();
    void readInfo();
    void displayError(QAbstractSocket::SocketError err);

private:
    Ui::Client *ui;

    QTcpSocket * serverSocket;
    QString message;
};

void operator >>(QDataStream &ds, StdInfo &d);

#endif // CLIENT_H
