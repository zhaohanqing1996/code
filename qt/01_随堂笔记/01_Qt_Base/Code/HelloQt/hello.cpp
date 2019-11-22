#include "hello.h"
#include "ui_hello.h"

Hello::Hello(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hello)
{
    ui->setupUi(this);

    this->setWindowTitle("牛叉叉");
}

Hello::~Hello()
{
    delete ui;
}
