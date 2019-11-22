#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this); 
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setServer(QTcpSocket *p)
{
    server = p;
    connect(server,SIGNAL(readyRead()),this,SLOT(readMsg()));
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->userNameLineEdit->text().isEmpty() || ui->passwdLineEdit->text().isEmpty())
    {
        return;
    }
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << ui->userNameLineEdit->text();
    out << ui->passwdLineEdit->text();
    server->write(block);
}

void LoginDialog::readMsg()
{
    QDataStream in(server);
    QString res;
    in.setVersion(QDataStream::Qt_5_5);
    in >> res;
    if(res == "Yes")
    {
        accept();
    }
}
