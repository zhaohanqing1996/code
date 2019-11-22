#include "settime_dialog.h"
#include "ui_settime_dialog.h"

QProcess *p;

setTime_Dialog::setTime_Dialog(QWidget *parent) : QDialog(parent),ui(new Ui::setTime_Dialog)
{
    ui->setupUi(this);
}

setTime_Dialog::~setTime_Dialog()
{
    delete ui;
}

void setTime_Dialog::on_sureBtn_clicked()
{
    //把分秒转化为秒
    int jumpTime=ui->minBox->value()*60+ui->secBox->value();
    p->write(QString("seek "+QString::number(jumpTime)+" 2\n").toUtf8());
    this->close();
}
