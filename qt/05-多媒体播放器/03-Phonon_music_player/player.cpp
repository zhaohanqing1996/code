#include "player.h"
#include "ui_player.h"
#include <QFileDialog>
#include <QKeyEvent>

Player::Player(QWidget *parent) :  QWidget(parent),  ui(new Ui::Player)
{
    ui->setupUi(this);
    mObject = new Phonon::MediaObject(this);
    vWidget = new Phonon::VideoWidget(ui->frameVideo);
    aOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    sSlider = new Phonon::SeekSlider(mObject,ui->frame);
    vSlider = new Phonon::VolumeSlider(aOutput,ui->frame_2);
    Phonon::createPath(mObject,vWidget);
    Phonon::createPath(mObject,aOutput);
    vWidget->installEventFilter(this);
}

Player::~Player()
{
    delete ui;
}
/*
void Player::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch(e->type()){
    case QEvevt::languageChange:ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
*/
void Player::on_btnMedia_clicked()
{
    QString filename =
            QFileDialog::getOpenFileName(this,tr("打开文件"),tr("E:\\多媒体\\电影"),"*.*");
    if(filename.isEmpty()||filename.isNull())
        return;
    //设置媒体源
    mObject->setCurrentSource(Phonon::MediaSource(filename));
}

void Player::on_btnPlay_clicked(bool checked)
{
    if(checked)
    {
        ui->btnPlay->setText(tr("暂停"));
        mObject->play();
    }else
    {
        ui->btnPlay->setText(tr("播放"));
        mObject->pause();
    }
}
void Player::resizeEvent(QResizeEvent *event)
{
    vWidget->setGeometry(
            ui->frameVideo->rect());
    sSlider->setGeometry(
            ui->frame->rect());
}
/*void Player::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(isFullScreen())
        vWidget->exitFullScreen();
    else
    {
        vWidget->setFullScreen(1);
    }
}*/
bool Player::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==vWidget)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            if(vWidget->isFullScreen())
            {
                vWidget->exitFullScreen();
                resizeEvent(NULL);
                return true;
            }else
            {
                vWidget->enterFullScreen();
            }
        }
        if(vWidget->isFullScreen())
        {
            if(((QKeyEvent*)event)->key()==Qt::Key_Escape)
            {
                vWidget->exitFullScreen();
                resizeEvent(NULL);
                return true;
            }

        }

    }
    return false;
}
