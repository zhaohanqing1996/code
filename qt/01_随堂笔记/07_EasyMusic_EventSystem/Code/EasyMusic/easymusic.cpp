#include "easymusic.h"
#include "ui_easymusic.h"

EasyMusic::EasyMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyMusic)
{
    ui->setupUi(this);

    mediaState = Pause;

    this->setWindowTitle("酷我音乐");

    player = new QMediaPlayer(this);
    mediaList = new QMediaPlaylist;
    mediaList->setPlaybackMode(QMediaPlaylist::Sequential);
    player->setPlaylist(mediaList);
    player->setVolume(50);


    showList = new QListWidget;
    showList->setMinimumSize(360, 700);
    showList->setMaximumSize(360, 700);
    showListState = false;

    ui->playRateSlider->setStyleSheet("QSlider::groove:horizontal{border:0px;height:4px;}"
                                      "QSlider::sub-page:horizontal{background:white;}"
                                      "QSlider::add-page:horizontal{background:lightgray;}" "QSlider::handle:horizontal{background:white;width:10px;border-radius:5px;margin:-3px 0px -3px 0px;}" );
    ui->volumeSlider->setStyleSheet("QSlider::groove:horizontal{border:0px;height:4px;}"
                                    "QSlider::sub-page:horizontal{background:white;}"
                                    "QSlider::add-page:horizontal{background:lightgray;}" "QSlider::handle:horizontal{background:white;width:10px;border-radius:5px;margin:-3px 0px -3px 0px;}");

    connect(ui->addSongBtn,SIGNAL(clicked(bool)),this,SLOT(addSongSlot()));
    connect(ui->showHideListBtn,SIGNAL(clicked(bool)),this,SLOT(updateShowListState()));
    connect(showList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(playMusic()));
    connect(ui->playPauseBtn,SIGNAL(clicked(bool)),this,SLOT(updateMediaPlayState()));
    connect(ui->playModeComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(updatePlayBackMode(int)));

    connect(showList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(updatePlayTip()));

    connect(mediaList,SIGNAL(currentIndexChanged(int)),this,SLOT(updateShowListRow(int)));

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(updateRateSliderValue(qint64)));
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(updateCurrentTime(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(updateRateSliderRange(qint64)));

    connect(ui->volumeSlider,SIGNAL(sliderMoved(int)),player,SLOT(setVolume(int)));

    connect(ui->playRateSlider,SIGNAL(sliderReleased()),this,SLOT(updatePlayPostion()));
    connect(ui->playRateSlider,SIGNAL(sliderPressed()),this,SLOT(disconnectSliderPlayer()));

    connect(ui->preSongBtn,SIGNAL(clicked(bool)),mediaList,SLOT(previous()));
    connect(ui->nextSongBtn,SIGNAL(clicked(bool)),mediaList,SLOT(next()));


}

EasyMusic::~EasyMusic()
{
    delete ui;
}

bool EasyMusic::isInFileList(QString &name)
{
    int i;
    for(i = 0; i < fileList.count(); i++)
    {
        if(fileList[i] == name)
        {
            return true;
        }
    }
    return false;
}

QString EasyMusic::timeToString(qint64 t)
{
    int sec = t / 1000;
    int min = sec / 60;
    sec = sec % 60;

    QString str;
    str.sprintf("%02d:%02d", min, sec);
    return str;
}


void EasyMusic::addSongSlot()
{
    QStringList nameList = QFileDialog::getOpenFileNames(this,"选择歌曲","C:/Users/huxings/Desktop/学习/qt素材/QT资源文件/music","音乐文件(*.mp3 *.wav *.avi);;所有文件(*)");

    if(nameList.count() == 0)
    {
        return;
    }
    int i;
    for(i = 0; i < nameList.count(); i++)
    {
        if(!isInFileList(nameList[i]))
        {
            fileList << nameList[i];
            mediaList->addMedia(QMediaContent(QUrl(nameList[i])));
        }
    }
    updateShowList();
}

void EasyMusic::updateShowList()
{
    showList->clear();
    foreach(QString s, fileList)
    {
        QFileInfo file(s);
        showList->addItem(file.fileName());
    }
}

void EasyMusic::updateShowListState()
{
    showListState = !showListState;
    if(showListState)
    {
        showList->show();
        ui->showHideListBtn->setText("隐藏列表");
    }
    else
    {
        showList->hide();
        ui->showHideListBtn->setText("显示列表");
    }
}

void EasyMusic::updateMediaPlayState()
{
    switch(mediaState)
    {
    case Play:
        mediaState = Pause;
        player->pause();
        ui->playPauseBtn->setText("播放");
        break;
    case Pause:
        mediaState = Play;
        player->play();
        ui->playPauseBtn->setText("暂停");
        break;
    }
}

void EasyMusic::updatePlayBackMode(int n)
{
    switch(n)
    {
    case 0: mediaList->setPlaybackMode(QMediaPlaylist::Sequential); break;
    case 1: mediaList->setPlaybackMode(QMediaPlaylist::Loop); break;
    case 2: mediaList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce); break;
    case 3: mediaList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop); break;
    case 4: mediaList->setPlaybackMode(QMediaPlaylist::Random); break;
    }
}

void EasyMusic::updateShowListRow(int n)
{
    showList->setCurrentRow(n);
    updatePlayTip();
}

void EasyMusic::updateRateSliderRange(qint64 dur)
{
    ui->playRateSlider->setRange(0, dur);
    ui->totalTimeLabel->setText(timeToString(dur));
}

void EasyMusic::updateRateSliderValue(qint64 pos)
{
    ui->playRateSlider->setValue(pos);
}

void EasyMusic::updatePlayPostion()
{
    qint64 w = ui->playRateSlider->value();
    player->setPosition(w);

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(updateRateSliderValue(qint64)));
}

void EasyMusic::disconnectSliderPlayer()
{
    disconnect(player,SIGNAL(positionChanged(qint64)),this,SLOT(updateRateSliderValue(qint64)));
}

void EasyMusic::updateCurrentTime(qint64 pos)
{
    ui->currentTimeLabel->setText(timeToString(pos));
}

void EasyMusic::updatePlayTip()
{
    qDebug() << "row: " << showList->currentRow();
    ui->titleLabel->setText("正在播放：" + showList->currentItem()->text());
}

void EasyMusic::playMusic()
{
    int row = showList->currentRow();

    qDebug() << "row: " << row;
    mediaList->setCurrentIndex(row);

    mediaState = Pause;
    updateMediaPlayState();
}
