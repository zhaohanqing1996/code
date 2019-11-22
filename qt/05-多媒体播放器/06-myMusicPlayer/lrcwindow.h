#ifndef LRCWINDOW_H
#define LRCWINDOW_H

#include <QLabel>
#include <QTimer>

class lrcWindow : public QLabel
{
    Q_OBJECT
public:
    lrcWindow(QWidget *parent);
    QAction *exit;
    void setTime(int num){time = num;}
    void setLrcWidth();
QTimer *timer;
private:
    QPoint dragPosition;
    int time;
    qreal length;
    qreal lrcWidth;
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void contextMenuEvent(QContextMenuEvent *ev);
    void paintEvent(QPaintEvent *);
private slots:
    void timeout();
};

#endif // LRCWINDOW_H
