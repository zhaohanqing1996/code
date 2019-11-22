#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QFileDialog>

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

    void newConnect();
    void displayError(QAbstractSocket::SocketError err);

    void readFileData();

    void on_connectBtn_clicked();

private:
    Ui::Client *ui;

    QTcpSocket * serverSocket;

    QString fileName;
    QString trueFile;
};



#endif // CLIENT_H
