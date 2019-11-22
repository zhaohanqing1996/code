#include "quitdialog.h"
#include "ui_quitdialog.h"

quitDialog::quitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quitDialog)
{
    ui->setupUi(this);
}

quitDialog::~quitDialog()
{
    delete ui;
}

void quitDialog::on_quitBtn_clicked()
{
    reject();
}

void quitDialog::on_stayBtn_clicked()
{
    accept();
}
