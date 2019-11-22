#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "quitdialog.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_quitBtn_clicked()
{
    quitDialog q(this);

    if(q.exec() == QDialog::Rejected)
    {
        this->close();
    }
}
