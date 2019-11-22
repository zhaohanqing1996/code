#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setLabelFontFamily(QFont p)
{
    qDebug() << "setLabelFont running....";
    f.setFamily(p.family());
    ui->textLabel->setFont(f);
}

void Widget::setLabelPointSize(int v)
{
    qDebug() << "setLabelPointSize running....";
    f.setPointSize(v);
    ui->textLabel->setFont(f);
}
