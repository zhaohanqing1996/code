#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    memberInit();
}

Server::~Server()
{
    delete ui;
}

void Server::sqliteInit()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "gold");
    db.setHostName("local");
    db.setDatabaseName("goldFlower.db");
    db.setUserName("hxzjh");
    db.setPassword("098234");
    if(!db.open())
    {
        QMessageBox::information(this,"打开失败","数据库文件打开失败!!!", QMessageBox::Ok);
        return;
    }
    QStringList list = db.tables();
    if(list.count() == 0)
    {
        QSqlQuery query(db);

        query.exec("create table userInfo(name varchar(40), passwd varchar(40))");
        query.exec("insert into userInfo values('pengjunqiang520', 'pjq520')");
        query.exec("insert into userInfo values('sdf3432454', '787685')");
        query.exec("insert into userInfo values('dfjj546', 'pyjytq520')");
        query.exec("insert into userInfo values('pnqia520', 'pdfhj520')");
        query.exec("insert into userInfo values('pedaiang520', 'pfgfg20')");
        query.exec("insert into userInfo values('pen12314ang520', '5dfdf20')");
        query.exec("insert into userInfo values('sdfdf', '67fgfh')");
        query.exec("insert into userInfo values('dsfhhj', 'ghhghf45')");
        query.exec("insert into userInfo values('5687th', 'dfgh78')");
    }
    qDebug() << "数据库启动完成";
}

void Server::listenSocketInit()
{
    listenSocket = new QTcpServer(this);
    if( !listenSocket->listen(QHostAddress::Any, 4567) )
    {
        QMessageBox::information(this,"监听失败","网络监听失败！！！");
        return;
    }
    connect(listenSocket,SIGNAL(newConnection()),this,SLOT(createServerThread()));
    qDebug() << "后台开始监听等待客户端";
}

void Server::memberInit()
{
    sqliteInit();
    listenSocketInit();
}

void Server::createServerThread()
{
    QTcpSocket * c = listenSocket->nextPendingConnection();
    ClientThread * thread = new ClientThread(c, db);
    thread->start();
}

