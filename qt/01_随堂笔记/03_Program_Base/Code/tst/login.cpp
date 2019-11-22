#include "login.h"
#include "ui_login.h"
#include <QPushButton>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QMovie *m = new QMovie(QString("C:/Users/huxings/Desktop/test.gif"));
    QPushButton *cBtn = new QPushButton(ui->label);

    cBtn->setIcon(QIcon(QString("C:/Users/huxings/Desktop/x.png")));
    cBtn->resize(46,31);
    cBtn->setFlat(true);
    cBtn->move(ui->label->width() - 46, 0);
    ui->label->setMovie(m);
    m->start();
}

Login::~Login()
{
    delete ui;
}
