#ifndef SETTIME_DIALOG_H
#define SETTIME_DIALOG_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class setTime_Dialog;
}

class setTime_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit setTime_Dialog(QWidget *parent = 0);
    ~setTime_Dialog();

private:
    Ui::setTime_Dialog *ui;

private slots:
    void on_sureBtn_clicked();
};

#endif // SETTIME_DIALOG_H
