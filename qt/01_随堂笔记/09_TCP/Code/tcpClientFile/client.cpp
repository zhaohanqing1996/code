#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    serverSocket = new QTcpSocket(this);

    connect(serverSocket,SIGNAL(readyRead()),this,SLOT(readFileData()));
    connect(serverSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    delete ui;
}

void Client::newConnect()
{
    serverSocket->abort();

    serverSocket->connectToHost(ui->addressLineEdit->text(),ui->portLineEdit->text().toInt());
}


void Client::displayError(QAbstractSocket::SocketError err)
{
    qDebug() << "错误：" << serverSocket->errorString();
}

void Client::readFileData()
{
    if(serverSocket->bytesAvailable() == 0)
    {
        return;
    }
    qDebug() << "读取文件数据";
    QFile file("C:/Users/huxings/Desktop/ss.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug() << "打开文件失败";
        return;
    }
    QByteArray block = serverSocket->readAll();
    file.write(block);
}


void Client::on_connectBtn_clicked()
{
    newConnect();
}
