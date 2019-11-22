#ifndef QQ_H
#define QQ_H

#include <QMainWindow>
#include<iostream>
using namespace std;
namespace Ui {
    class QQ;
}

class QQ : public QMainWindow
{
    Q_OBJECT

public:
    explicit QQ(QWidget *parent = 0);
    ~QQ();

private:
    Ui::QQ *ui;

private slots:
    void on_quit_released();
    void on_login_released();
};

#endif // QQ_H
