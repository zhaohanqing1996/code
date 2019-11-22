#ifndef EASYPIC_H
#define EASYPIC_H

#include <QWidget>
#include <QFileDialog>
#include <QStringList>
#include <QMessageBox>

namespace Ui {
class EasyPic;
}

class EasyPic : public QWidget
{
    Q_OBJECT

public:
    explicit EasyPic(QWidget *parent = 0);
    ~EasyPic();

public:
    void showPic();

private:
    bool isExist(QString &name);
    void updateBtnState();

private slots:
    void on_localFileBtn_clicked();

    void on_preBtn_clicked();

    void on_nextBtn_clicked();

    void on_addBtn_clicked();

    void on_deleteBtn_clicked();

private:
    Ui::EasyPic *ui;
    QStringList fileNames;
    int index;                  // 显示使用的下标
};

#endif // EASYPIC_H
