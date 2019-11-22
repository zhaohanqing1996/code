#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    memberInit();
}

Client::~Client()
{
    delete ui;
}

void Client::memberInit()
{
    serverSocket = new QTcpSocket(this);
    serverSocket->connectToHost(QHostAddress("192.168.10.14"), 4567);

    login = new LoginDialog;
    login->setServer(serverSocket);

    if(login->exec() != QDialog::Accepted)
    {
        login->close();
        this->close();
    }
    else
    {
        this->show();
    }
}
