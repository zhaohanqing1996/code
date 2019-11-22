#ifndef HELLO_H
#define HELLO_H

#include <QWidget>

namespace Ui {
class Hello;
}

class Hello : public QWidget
{
    Q_OBJECT

public:
    explicit Hello(QWidget *parent = 0);
    ~Hello();

private:
    Ui::Hello *ui;
};

#endif // HELLO_H
