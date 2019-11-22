#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    serverSocket = new QTcpSocket(this);

    connect(serverSocket,SIGNAL(readyRead()),this,SLOT(readInfo()));
    connect(serverSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    delete ui;
}

void Client::on_connectBtn_clicked()
{
    newConnect();

}

void Client::newConnect()
{
    serverSocket->abort();

    serverSocket->connectToHost(ui->addressLineEdit->text(),ui->portLineEdit->text().toInt());
}

void Client::readInfo()
{
    if(serverSocket->bytesAvailable() == 0)
    {
        return;
    }
    QDataStream out(serverSocket);
    out.setVersion(QDataStream::Qt_5_5);

    StdInfo mm;

    out >> mm;
    QString str = QString("姓名：%1  年龄：%2  性别：%3  身高：%4").arg(mm.name).arg(mm.age).arg(mm.sex).arg(mm.high);
    ui->msgLabel->setText(str);
}

void Client::displayError(QAbstractSocket::SocketError err)
{
    qDebug() << "错误：" << serverSocket->errorString();
}

void operator >>(QDataStream &ds, StdInfo &d)
{
    ds >> d.name;
    ds >> d.age;
    ds >> d.sex;
    ds >> d.high;
}
