#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpServer>   // 监听套接字
#include <QTcpSocket>   // 通信套接字
#include <QHostAddress>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

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
    void updateSendFileBtnState();

    void updateRateValue(qint64 n);

private slots:
    void on_sendFileBtn_clicked();

private:
    Ui::Server *ui;

    QTcpServer * listenSocket;

    QTcpSocket * clientSocket;

    quint64 totalSize;       // 文件总大小
    quint64 sendSize;        // 已发送大小
    quint64 nSize;           // 每次发送大小

    QFile * file;

    QByteArray block;       // 缓存区

};

#endif // SERVER_H
