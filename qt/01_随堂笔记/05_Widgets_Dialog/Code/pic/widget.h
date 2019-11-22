#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void loadPic(int i);

    bool isExist(QString &s);

    void updateLocateRange();
    void updateLocateValue();
    void updateBtnEnable();

private slots:
    void on_localFileBtn_clicked();

    void on_nextBtn_clicked();

    void on_preBtn_clicked();

    void on_delBtn_clicked();

    void on_addBtn_clicked();

    void on_locateSpinBox_editingFinished();

    void on_moveSlider_sliderMoved(int position);

private:
    Ui::Widget *ui;
    int currentIndex;       // 使用列表中当前下标
    QStringList fileNames;
    int isNeedShow;
};

#endif // WIDGET_H
