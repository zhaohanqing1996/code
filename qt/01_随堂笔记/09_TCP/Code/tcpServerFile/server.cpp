#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    totalSize = 0;
    sendSize = 0;
    ui->sendFileBtn->setEnabled(false);
    listenSocket = new QTcpServer(this);
    if(!listenSocket->listen(QHostAddress::Any, 6666))
    {
        qDebug() << "监听失败：" << listenSocket->errorString();
        this->close();
    }
    connect(listenSocket,SIGNAL(newConnection()),this,SLOT(updateSendFileBtnState()));

}

Server::~Server()
{
    delete ui;
}

void Server::updateSendFileBtnState()
{
    clientSocket = listenSocket->nextPendingConnection();
    ui->sendFileBtn->setEnabled(true);

    connect(clientSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(updateRateValue(qint64)));
}

void Server::updateRateValue(qint64 n)
{
    qDebug() << "n = " << n;
    sendSize += n;

       qDebug() << "发送.......";
       block = file->read(qMin(nSize, totalSize-sendSize));
       clientSocket->write(block);
       block.resize(0);
       ui->rateProgressBar->setValue(sendSize);

}



void Server::on_sendFileBtn_clicked()
{
    QString name = QFileDialog::getOpenFileName(this,"选择文件","D:/","文本文件(*.txt);;源文件(*.c *.cpp);;工程文件(*.pro);;图片文件(*.jpg *.png);;所有文件(*)");
    if(name.isEmpty())
    {
        return;
    }
    qDebug() << "获取文件名：" << name;
    file = new QFile(name);
    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "Server: 打开文件失败";
        return;
    }
    qDebug() << "文件打开成功！！！";
    totalSize = file->size();
    qDebug() << "获取文件总大小：" << totalSize;
    // name: D:/LOVE/a.txt   --> QFile

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << QString("hehe");
    clientSocket->write(block);

    ui->rateProgressBar->setMaximum(totalSize);
    block.resize(0);
}
