#include "qq.h"
#include "ui_qq.h"
#include <QtDebug>
#include <QMessageBox>

QQ::QQ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QQ)
{
    ui->setupUi(this);
    QObject::connect(ui->login,SIGNAL(pressed()),this,SLOT(on_login_released()));
    QObject::connect(ui->quit,SIGNAL(pressed()),this,SLOT(on_quit_released()));
}

QQ::~QQ()
{
    delete ui;
}

void QQ::on_login_released()
{

    if((ui->inNum->text() == "123456") && (ui->inPasswd->text() == "abcdef"))
    {
        cout << "login sucessed" <<endl;
    }
    else
    {
        qDebug("num or passwd error");
    }

}

void QQ::on_quit_released()
{
    this->close();
}
