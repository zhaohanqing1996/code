#include "easypic.h"
#include "ui_easypic.h"

EasyPic::EasyPic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyPic)
{
    ui->setupUi(this);

    index = 0;
    updateBtnState();

    this->setMaximumSize(720, 360);
    this->setMinimumSize(720, 360);

    ui->showLabel->setScaledContents(true);

}

EasyPic::~EasyPic()
{
    delete ui;
}

void EasyPic::showPic()
{
    QPixmap pic(fileNames[index]);

    ui->showLabel->setPixmap(pic);

    int labelWidth = this->width() - ui->addBtn->width() - 20;
    int labelHight = this->height() - ui->addBtn->height() - 20;
    int picWidtd = pic.width();
    int picHeight = pic.height();

    double widthScale = picWidtd * 1.0 / labelWidth;
    double hightScale = picHeight * 1.0 / labelHight;

    if(widthScale <= 1 && hightScale <= 1)
    {
        ui->showLabel->resize(picWidtd, picHeight);
    }
    else
    {
        if(widthScale > hightScale)
        {
            ui->showLabel->resize(labelWidth, picHeight / widthScale);
        }
        else
        {
            ui->showLabel->resize(picWidtd / hightScale, labelHight);
        }
    }


}

bool EasyPic::isExist(QString &name)
{
    for(int i = 0; i < fileNames.count(); i++)
    {
        if(fileNames[i] == name)
        {
            return true;
        }
    }
    return false;
}

void EasyPic::updateBtnState()
{
    if(fileNames.count() == 0)
    {
        ui->preBtn->setEnabled(false);
        ui->nextBtn->setEnabled(false);
        ui->deleteBtn->setEnabled(false);
    }
    else
    {
        ui->preBtn->setEnabled(true);
        ui->nextBtn->setEnabled(true);
        ui->deleteBtn->setEnabled(true);
        if(index == 0)
        {
            ui->preBtn->setEnabled(false);
        }
        if(index == fileNames.count() - 1)
        {
            ui->nextBtn->setEnabled(false);
        }
    }
}

void EasyPic::on_localFileBtn_clicked()
{
    fileNames = QFileDialog::getOpenFileNames(this,"选择图片","C:/Users/huxings/Desktop/学习/qt素材","所有文件(*);;图片文件(*.jpg *.png *.ico)");

    if(fileNames.count() == 0)
    {
        QMessageBox::information(this,"选择异常","大哥，咱好好的选一些图片行吗？？？");
        return;
    }
    updateBtnState();
    showPic();
    ui->localFileBtn->setEnabled(false);
}

void EasyPic::on_preBtn_clicked()
{
    if(index == 0)
    {
        return;
    }
    index--;
    updateBtnState();
    showPic();
}

void EasyPic::on_nextBtn_clicked()
{
    if(index == fileNames.count()-1 )
    {
        return;
    }
    index++;
    updateBtnState();
    showPic();
}

void EasyPic::on_addBtn_clicked()
{
    QStringList names = QFileDialog::getOpenFileNames(this,"选择图片","C:/Users/huxings/Desktop/学习/qt素材","所有文件(*);;图片文件(*.jpg *.png *.ico)");
    if(names.count() == 0)
    {
        QMessageBox::information(this,"添加失败","大哥，咱好好的选一些图片行吗？？？");
        return;
    }
    for(int i = 0; i < names.count(); i++)
    {
        if(!isExist(names[i]))
        {
            fileNames.insert(index, names[i]);
        }
    }
    updateBtnState();
    showPic();
}

void EasyPic::on_deleteBtn_clicked()
{
    if(index == -1)
    {
        return;
    }
    if(index == fileNames.count() - 1)
    {
       fileNames.removeAt(index);
       index--;
       if(index == -1)
       {
           index = 0;
           updateBtnState();
           ui->showLabel->clear();
           return;
       }
    }
    else
    {
        fileNames.removeAt(index);
    }
    updateBtnState();
    showPic();
}
