#ifndef GIFLABEL_H
#define GIFLABEL_H

#include <QLabel>
#include <QDebug>
#include <QMovie>
#include <QEvent>

class GifLabel : public QLabel
{
    Q_OBJECT

public:
    explicit GifLabel(QString gif, QWidget *parent = 0);
    ~GifLabel();

signals:
    void mouseIn();
    void mouseLeft();

protected:
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

private:
    QMovie *m;
};

#endif // GIFLABEL_H
