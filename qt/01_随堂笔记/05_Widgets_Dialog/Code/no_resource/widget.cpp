#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
                            //

    ui->picLabel->setPixmap(QPixmap(":/login/picture/xx.jpg"));


}

Widget::~Widget()
{
    delete ui;
}
