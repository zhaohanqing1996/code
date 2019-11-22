#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->idComboBox->currentText() == QString("sbs520") && ui->passwdLineEdit->text() == QString("5201314"))
    {
        accept();
    }
    else
    {
        if(ui->idComboBox->currentText() != QString("sbs520"))
        {
            ui->msgLabel->setText("账号不存在");
        }
        else if(ui->passwdLineEdit->text() != QString("5201314"))
        {
            ui->msgLabel->setText("密码错误");
        }
    }
}
