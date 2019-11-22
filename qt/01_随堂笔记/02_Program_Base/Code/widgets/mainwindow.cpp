#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // https://www.baidu.com/
    QString url = ui->lineEdit->text();
    url = "https://" + url;
    ui->webView->setUrl(QUrl(url));
}
