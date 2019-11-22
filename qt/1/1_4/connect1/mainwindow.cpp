#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加信号槽关联代码，必须放在 setupUi 函数之后。
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//槽函数定义代码，与普通成员函数写法一样（没有返回值）
void MainWindow::pushButton_clicked()
{
    QMessageBox::information(NULL,"信号与槽函数学习","信号接收成功!!");
}

