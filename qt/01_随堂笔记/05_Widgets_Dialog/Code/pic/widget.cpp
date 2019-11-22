#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    currentIndex = 0;
    isNeedShow = 1;
    updateBtnEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadPic(int i)
{
    QPixmap mp(fileNames[i]);
    int tw = mp.width();
    int th = mp.height();
    int w = this->width() - 134;
    int h = this->height() - 32;

    if(tw <= w && th <= h)
    {
        ui->picLabel->setMinimumSize(tw, th);
        ui->picLabel->setMaximumSize(tw, th);
        ui->picLabel->setPixmap(mp);
    }
    else
    {
        double wb = tw / w;
        double hb = th / h;
        if(wb > hb)
        {

            double hs = th * w / tw;
            ui->picLabel->setMinimumSize(w, hs);
            ui->picLabel->setMaximumSize(w, hs);
            ui->picLabel->setScaledContents(true);
            ui->picLabel->setPixmap(mp);
        }
        else
        {
            double ws = tw * h / th;
            ui->picLabel->setMinimumSize(ws, h);
            ui->picLabel->setMaximumSize(ws, h);
            ui->picLabel->setScaledContents(true);
            ui->picLabel->setPixmap(mp);
        }
    }
}

bool Widget::isExist(QString &s)
{
    int i;

    for(i = 0; i < fileNames.count(); i++)
    {
        if(s == fileNames[i])
        {
            return true;
        }
    }
    return false;
}

void Widget::updateLocateRange()
{
    ui->locateSpinBox->setRange(1, fileNames.count());
    ui->moveSlider->setRange(0, fileNames.count() * 10 - 1);

    // 0 --- 99
}

void Widget::updateLocateValue()
{
    ui->locateSpinBox->setValue(currentIndex + 1);
    ui->moveSlider->setValue(currentIndex * 10 + 5);
}

void Widget::updateBtnEnable()
{
    if(fileNames.count() == 0)
    {
        ui->preBtn->setEnabled(false);
        ui->nextBtn->setEnabled(false);
        ui->delBtn->setEnabled(false);
        return;
    }
    // 上一张
    if(currentIndex == 0)
    {
        ui->preBtn->setEnabled(false);
    }
    else
    {
        ui->preBtn->setEnabled(true);
    }
    // 下一张
    if(currentIndex == fileNames.count() - 1)
    {
        ui->nextBtn->setEnabled(false);
    }
    else
    {
        ui->nextBtn->setEnabled(true);
    }
    if(fileNames.count() > 0)
    {
        ui->delBtn->setEnabled(true);
    }
}

void Widget::on_localFileBtn_clicked()
{
    QStringList list = QFileDialog::getOpenFileNames(this, "选择图片", "C:/Users/huxings/Desktop/学习/qt素材/QT资源文件/文件/", "图片文件(*.png *.jpg);;所有文件(*)");

    for(int i = 0; i < list.count(); i++)
    {
        if(isExist(list[i]))
        {
            continue;
        }
        fileNames.append(list[i]);
    }
    updateLocateRange();
    updateBtnEnable();
    if(!fileNames.count())
    {
        QMessageBox::information(this,"选择图片失败","没有选择任何一张图片进行加载",QMessageBox::Ok);
        return;
    }
    if(isNeedShow)
    {
        loadPic(0);
        currentIndex = 0;
        isNeedShow = 0;
        updateLocateValue();
    }
}

void Widget::on_nextBtn_clicked()
{
    if(currentIndex == fileNames.count() - 1)
    {
        return;
    }
    currentIndex++;
    loadPic(currentIndex);
    updateLocateValue();
    updateBtnEnable();
}

void Widget::on_preBtn_clicked()
{
    if(currentIndex == 0)
    {
        return;
    }
    currentIndex--;
    loadPic(currentIndex);
    updateLocateValue();
    updateBtnEnable();
}

void Widget::on_delBtn_clicked()
{
    if(currentIndex < 0)
    {
        QMessageBox::warning(this,"删除毛线","没有图片，不能进行删除操作",QMessageBox::Ok);
        return;
    }
    if(currentIndex == fileNames.count() - 1)
    {
        fileNames.removeAt(currentIndex);
        currentIndex--;
        updateLocateValue();
        updateBtnEnable();
    }
    else if(currentIndex >= 0)
    {
        fileNames.removeAt(currentIndex);
    }
    if(currentIndex >= 0)
    {
        loadPic(currentIndex);
    }
    else
    {
        ui->picLabel->clear();
        isNeedShow = 1;
    }
    updateLocateRange();
    updateBtnEnable();
}

void Widget::on_addBtn_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "选择图片", "C:/Users/huxings/Desktop/学习/qt素材/QT资源文件/文件/", "图片文件(*.png *.jpg);;所有文件(*)");

    if(isExist(str))
    {
        return;
    }
    fileNames.insert(currentIndex+1, str);
    updateLocateRange();
}

void Widget::on_locateSpinBox_editingFinished()
{
    currentIndex = ui->locateSpinBox->text().toInt() - 1;
    loadPic(currentIndex);
    updateLocateValue();
    updateBtnEnable();
}

void Widget::on_moveSlider_sliderMoved(int position)
{
    int index = currentIndex;
    int i = position / 10;

    if(i == index)
    {
        return;
    }
    currentIndex = i;
    updateLocateValue();
    updateBtnEnable();
    loadPic(currentIndex);
}
