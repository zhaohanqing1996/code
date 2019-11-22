#include "easymusic.h"
#include "ui_easymusic.h"

EasyMusic::EasyMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyMusic)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    mediaList = new QMediaPlaylist;
    player->setPlaylist(mediaList);

    showList = new QListWidget;
    showList->setMinimumSize(300, 700);
    showList->setMaximumSize(300, 700);
    showListState = false;

    connect(ui->addSongBtn,SIGNAL(clicked(bool)),this,SLOT(addSongSlot()));
    connect(ui->showHideListBtn,SIGNAL(clicked(bool)),this,SLOT(updateShowListState()));
    connect(showList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(playMusic()));
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

void EasyMusic::playMusic()
{
    int row = showList->currentRow();

    qDebug() << "row: " << row;
    mediaList->setCurrentIndex(row);
    player->play();
}
