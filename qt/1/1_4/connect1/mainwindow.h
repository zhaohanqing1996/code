#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots: //槽函数声明标志
void pushButton_clicked(); //声明槽函数

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
