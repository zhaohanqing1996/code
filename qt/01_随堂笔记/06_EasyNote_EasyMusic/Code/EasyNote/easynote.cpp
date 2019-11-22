#include "easynote.h"
#include "ui_easynote.h"

EasyNote::EasyNote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EasyNote)
{
    ui->setupUi(this);

    isChange = false;
    hasTarget = false;
    targetFilePath = "";
    targetFileName = "";

    updateTitle();

    connect(ui->openFileAction,SIGNAL(triggered(bool)),this,SLOT(openFileSlot()));
    connect(ui->saveFileAsAction,SIGNAL(triggered(bool)),this,SLOT(saveFileAsSlot()));
    connect(ui->saveFileAction,SIGNAL(triggered(bool)),this,SLOT(saveFileSlot()));
    connect(ui->contentTextEdit,SIGNAL(textChanged()),this,SLOT(updateChangeState()));
    connect(ui->newFileAction,SIGNAL(triggered(bool)),this,SLOT(newFileSlot()));
    connect(ui->quitAciton,SIGNAL(triggered(bool)),this,SLOT(close()));
}

EasyNote::~EasyNote()
{
    delete ui;
}

void EasyNote::updateTitle()        // a.txt - 记事本
{
    qDebug() << "xxxxx";
    QString str;

    if(hasTarget)
    {
        str = targetFileName + " - 记事本";
    }
    else
    {
        str = "无标题 - 记事本";
    }
    if(isChange)
    {
        str += " *";
    }
    qDebug() << "str: " << str;
    this->setWindowTitle(str);
}

void EasyNote::newFileSlot()
{
    EasyNote * newNote = new EasyNote;

    newNote->show();
}

void EasyNote::openFileSlot()
{
    // 1.通过文件对话框获取用户选择文件的文件名（含路径）
    QString name = QFileDialog::getOpenFileName(this,"打开文件","D:/","文本文件(*.txt);;所有文件(*)");
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"选择文件失败","哥哥，你到是选一个文件啊");
        return;
    }
    // 2.利用文件名（含路径）创建一个文件对象
    QFile targetFile(name);

    if(!targetFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"打开文件失败","哥哥，你是不是坑我了?");
        return;
    }
    // 3.创建一个文件流对象 对 文件进行读写操作
    QTextStream readStream(&targetFile);

    ui->contentTextEdit->setPlainText(readStream.readAll());

    // 4.更新是否有目标状态
    hasTarget = true;

    // 5.获取目标文件的文件名（有路径、无路径）
    QFileInfo info(targetFile);

    targetFileName = info.fileName();
    targetFilePath = info.filePath();

    updateTitle();

}

void EasyNote::saveFileAsSlot()
{
    QString name = QFileDialog::getSaveFileName(this,"另存为","D:/","文本文件(*.txt);;所有文件(*)");
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"另存为失败","小伙子，你搞事情啊");
        return;
    }
    QFile file(name);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"创建文件失败","我也不知道怎么回事!!!");
        return;
    }
    QTextStream out(&file);
    out << ui->contentTextEdit->toPlainText();
    if(hasTarget == false)
    {
        hasTarget = true;
        QFileInfo info(file);

        targetFileName = info.fileName();
        targetFilePath = info.filePath();
        updateTitle();
    }
}

void EasyNote::saveFileSlot()
{
    if(!isChange)
    {
        return;
    }
    isChange = false;
    if(hasTarget)
    {
        QFile file(targetFilePath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"保存文件失败","我也不知道怎么回事!!!");
            return;
        }
        QTextStream out(&file);
        out << ui->contentTextEdit->toPlainText();
        updateTitle();
        return;
    }
    saveFileAsSlot();
}

void EasyNote::updateChangeState()
{
    if(isChange == false)
    {
        isChange = true;
        updateTitle();
    }
}
