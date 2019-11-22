#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <phonon>
#include <QEvent>

namespace Ui {
    class Player;
}

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    ~Player();
/*
protected:
    void changeEvent(QEvent *e);
*/
private:
    Ui::Player *ui;
    Phonon::MediaObject * mObject;
    Phonon::VideoWidget * vWidget;
    Phonon::AudioOutput * aOutput;
    Phonon::SeekSlider  * sSlider;
    Phonon::VolumeSlider * vSlider;

    void resizeEvent ( QResizeEvent * event );
    //void mouseDoubleClickEvent(QMouseEvent *event);
protected:
    bool eventFilter ( QObject * watched, QEvent * event );

private slots:
    void on_btnPlay_clicked(bool checked);
    void on_btnMedia_clicked();
};

#endif // PLAYER_H
