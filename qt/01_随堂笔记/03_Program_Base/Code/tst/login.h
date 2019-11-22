#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
