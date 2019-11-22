#ifndef QUITDIALOG_H
#define QUITDIALOG_H

#include <QDialog>

namespace Ui {
class quitDialog;
}

class quitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit quitDialog(QWidget *parent = 0);
    ~quitDialog();

private slots:
    void on_quitBtn_clicked();

    void on_stayBtn_clicked();

private:
    Ui::quitDialog *ui;
};

#endif // QUITDIALOG_H
