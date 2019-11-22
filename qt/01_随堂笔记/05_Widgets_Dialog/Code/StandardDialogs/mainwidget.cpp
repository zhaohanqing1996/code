#include "mainwidget.h"
#include "ui_mainwidget.h"

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

void MainWidget::on_colorBtn_clicked()
{
    QColor chose = QColorDialog::getColor(Qt::red, this, "选择颜色");

    if(!chose.isValid())
    {
        qDebug() << "哥，别玩我了，好好选一个颜色吧" << chose;
    }
    else
    {
        qDebug() << "颜色：" << chose;
    }

}

void MainWidget::on_fileBtn_clicked()
{
    QString filter = "文本文件(*.txt *.doc);;图片(*.jpg *.png);;音乐(*.mp3 *.wav);;所有文件(*)";
//    QString fileName = QFileDialog::getOpenFileName(this,"打开文件","D:/",filter);
//    qDebug() << "fileName: " << fileName;

    QStringList fileNames = QFileDialog::getOpenFileNames(this,"选择文件","D:/", filter);

    for(int i = 0; i < fileNames.count(); i++)
    {
        qDebug() << i << ": " << fileNames[i];
    }
}
