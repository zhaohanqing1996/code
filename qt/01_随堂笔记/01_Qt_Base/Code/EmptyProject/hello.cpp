#include "hello.h"
#include "ui_hello.h"

Hello::Hello(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hello)
{
    ui->setupUi(this);
}

Hello::~Hello()
{
    delete ui;
}
