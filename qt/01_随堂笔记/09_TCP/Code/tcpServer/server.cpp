#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    listenSocket = new QTcpServer(this);
    if(!listenSocket->listen(QHostAddress::Any, 6666))
    {
        qDebug() << "监听失败：" << listenSocket->errorString();
        this->close();
    }
    connect(listenSocket,SIGNAL(newConnection()),this,SLOT(sendMessage()));
}

Server::~Server()
{
    delete ui;
}

void Server::sendMessage()
{
    QTcpSocket * communicateSocket = listenSocket->nextPendingConnection();

    QByteArray data;

    QDataStream in(&data, QIODevice::WriteOnly);
    in.setVersion(QDataStream::Qt_5_5);

    if(ui->nameLineEdit->text().isEmpty())
    {
        return;
    }
    if(ui->ageSpinBox->value() == 0)
    {
        return;
    }
    if(ui->highDoubleSpinBox->value() == 0.0)
    {
        return;
    }



    StdInfo msg;
    msg.name = ui->nameLineEdit->text();         // QString
    msg.age = ui->ageSpinBox->value();          // int
    msg.sex = ui->sexComboBox->currentText();   // QString
    msg.high = ui->highDoubleSpinBox->value();   // double

    in << msg;          // StdInfo


    communicateSocket->write(data);


    // 发送信息：
    //      char *          纯文本  "I LOVE YOU"
    //      QByteArray             12   12.56   QColor  QPoint

}

void operator <<(QDataStream &ds, StdInfo &d)
{
    ds << d.name;
    ds << d.age;
    ds << d.sex;
    ds << d.high;
}
