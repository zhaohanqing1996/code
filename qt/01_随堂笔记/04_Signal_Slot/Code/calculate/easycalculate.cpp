#include "easycalculate.h"
#include "ui_easycalculate.h"

EasyCalculate::EasyCalculate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyCalculate)
{
    ui->setupUi(this);
}

EasyCalculate::~EasyCalculate()
{
    delete ui;
}

void EasyCalculate::on_btn1_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "1");
}

void EasyCalculate::on_btn2_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "2");
}

void EasyCalculate::on_btn3_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "3");
}

void EasyCalculate::on_btn4_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "4");
}

void EasyCalculate::on_btn5_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "5");
}

void EasyCalculate::on_btn6_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "6");
}

void EasyCalculate::on_btn7_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "7");
}

void EasyCalculate::on_btn8_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "8");
}

void EasyCalculate::on_btn9_clicked()
{
    ui->showLineEdit->setText(ui->showLineEdit->text() + "9");
}

void EasyCalculate::on_clearOneBtn_clicked()
{
    QString str = ui->showLineEdit->text();
    int value = str.toInt();
    value = value / 10;

    if(value == 0)
    {
        ui->showLineEdit->clear();
    }
    else
    {
        ui->showLineEdit->setText(QString("%1").arg(value));
    }
}

void EasyCalculate::on_clearAllBtn_clicked()
{
    ui->showLineEdit->clear();
}
