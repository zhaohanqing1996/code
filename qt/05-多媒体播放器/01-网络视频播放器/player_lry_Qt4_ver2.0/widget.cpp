#include "widget.h"
#include "ui_widget.h"
#include "settime_dialog.h"
#include <QWidget>
#include <QTime>
#include <QLayoutItem>
#include <Qt>

extern QProcess *p;  //进程
QString absolutepath;//保存播放文件的绝对路径,保存播放文件的绝对路径，bug是不能播放多个路径下的文件
Widget::Widget(QWidget *parent) :QWidget(parent),ui(new Ui::Widget)
{
	ui->setupUi(this);
	manager = NULL;
    timer = NULL;             //定时器初始化
    isNetworkPlay = false;    //开机默认是本地播放
    p=new QProcess(this);     //创建一个进程
    //如果该进程有数据输出则进入槽函数
	connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
    //ui->hBoxLayout_btn->setAlignment(Qt::AlignHCenter);//设置这些按钮水平居中对齐,弄了很久才实现这一点功能
}
Widget::~Widget()
{
	delete ui;
}

void Widget::play(QString fileName)   //播放视频
{
	QStringList args;
    p->kill();               //每次点击播放都先杀死上次播放的进程
    p=new QProcess(this);    //重新建一个进程
    connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));//为刚刚建的进程创建连接
    args<<"-slave";          //从模式
    args<<"-quiet";          //不输出冗余的信息
    args<<"-wid"<<QString::number((int)ui->label_PlayArea->winId()); //在哪个窗口播放视频
	//我在此处view前面加了个(int)强制转换下就能编译通过，原本没有
    args<<"-zoom";           //尺寸
	args<<"-x";
	args<<"161";
	args<<"-y";
	args<<"225";
    //args<<"-vo";//注意：如果是在开发板上运行，去掉本行和下面的一行代码
    //args<<"gl2";//x11:for Linux/XWindows,  gl2: for Windows
    if(isNetworkPlay)        //如果是网络播放
	{
		this->setWindowTitle("正在播放网络视频 "+fileName);
		args<<HTTP_URL+fileName;//播放http服务器上的视频
	}
	else
	{
		this->setWindowTitle("正在播放本地视频 "+fileName);
		args<<absolutepath+fileName;//播放本地视频
	}
    p->start("mplayer",args);  //开始播放视频
}

void Widget::on_btn_add_clicked()  //点击打开本地按钮
{
	QStringList fileNames=QFileDialog::getOpenFileNames(this,"打开文件","./","音视频 (*.rmvb *.flv *.rm *.3gp *.m4v *.mp4 *.avi *.wmv *.mpg *.mp3);;All Files (*)");
    if(fileNames.count()!=0)       //如果选择了视频
	{
		/*把文件信息列表中的视频文件的目录路径去掉*/
        QFileInfo fi = fileNames.at(0);       //任意取出一个文件信息
		fileNames.replaceInStrings("\\", "/");        
        absolutepath = fi.absolutePath()+"/"; //保存路径
		absolutepath.replace("\\", "/");//把反斜杠(\)换成正斜杠(/)
        //ui->label_out->setText(absolutepath);//用于调试
		fileNames.replaceInStrings(absolutepath, "");//去掉目录路径

        //将打开对话框返回的文件信息添加到列表playlist里
		ui->playlist->addItems(fileNames);
		ui->playlist->setCurrentRow(0);//打开文件之初设置当前列表项为第一项
	}
	isNetworkPlay = false;
}

void Widget::on_btn_del_clicked()  //删除列表中的视频
{
	if(ui->playlist->currentRow() == -1 )
		QMessageBox::warning(this,"提示","未选中项目或列表为空",QMessageBox::Yes);
	else
		ui->playlist->takeItem(ui->playlist->currentRow());//删除播放列表中指定的那一项
}

void Widget::on_playlist_itemDoubleClicked(QListWidgetItem* item)
{
	ui->btn_stop->setEnabled(true);
	ui->btn_prev->setEnabled(true);
	ui->btn_next->setEnabled(true);
	ui->btn_setTime->setEnabled(true);
	ui->btn_setSpeed->setEnabled(true);
	ui->processSlider->setEnabled(true);
	ui->volumeSlider->setEnabled(true);
	play(item->text());//
	isNetworkPlay = false;
	ui->btn_play->setText("暂停");
}

void Widget::on_btn_play_clicked()   //如果点击播放
{
    //如果当前是本地播放     并且    列表为空                        并且        播放按钮当前显示播放    并且暂停按钮是禁止的
	if( isNetworkPlay == false && ui->playlist->count() == 0 && ui->btn_play->text() == QString("播放") && ui->btn_stop->isEnabled() == false)
        on_btn_add_clicked();   //添加文件
    //如果是网络播放                      并且网络播放列表为空                       并且  当前播放按钮显示播放                 并且暂停按钮是禁止的
	else if(isNetworkPlay == true && ui->playlist_net->count() == 0 && ui->btn_play->text() == QString("播放") && ui->btn_stop->isEnabled() == false)
		QMessageBox::warning(this,"提示","网络播放列表为空!",QMessageBox::Yes);
    //如果当前是播放时的暂停状态
    else if(ui->btn_play->text()==QString("播放"))
    {   //如果暂停按钮是使能的
		if(ui->btn_stop->isEnabled() == true)//正在播放的中途，处于暂停的状态
        {   //建立连接，接收播放器进程弹出的信息
			connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
            p->write("pause\n");        //继续播放
			ui->btn_play->setText("暂停");
		}
        //如果暂停按钮是禁止的（说明要播放一个新的视频）
		else
		{
            //如果是本地播放
			if(isNetworkPlay == false)
				play(ui->playlist->currentItem()->text());//处于未播放视频的状态,点击【播放】按钮就播放列表中当前那一项的文件
            //如果是网络播放
            else
				play(ui->playlist_net->currentItem()->text());//处于未播放视频的状态,点击【播放】按钮就播放列表中当前那一项的文件

            p->write("get_time_length\n");   //获得总长度
            p->write("get_time_pos\n");      //获得当前位置（秒数）
            p->write("get_percent_pos\n");   //返回文件的百分比

            ui->btn_stop->setEnabled(true);  //使能以下按钮
			ui->btn_prev->setEnabled(true);
			ui->btn_next->setEnabled(true);
			ui->btn_setTime->setEnabled(true);
			ui->btn_setSpeed->setEnabled(true);
			ui->volumeSlider->setEnabled(true);
			ui->processSlider->setEnabled(true);
			ui->btn_play->setText("暂停");
		}
	}
    //如果当前正在播放
	else if(ui->btn_play->text()==QString("暂停"))
	{
        p->write("pause\n");    //停止播放
        //取消接收播放器的进程打印的信息
		disconnect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
		ui->btn_play->setText("播放");
	}

}

void Widget::on_btn_stop_clicked()  //如果是按下停止按钮
{   //不再接收播放器进程打印的信息
	disconnect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
    p->write("quit\n");             //停止mplayer播放
    ui->label_time->clear();        //清除播放时间
    ui->label_percent->clear();     //清除进度显示
    ui->processSlider->setValue(0); //进度条设置成0
    ui->btn_stop->setEnabled(false);//禁止使能按钮按钮
    ui->btn_play->setText("播放");   //播放按钮显示播放
}

void Widget::on_btn_prev_clicked()  //如果按下上一首的按钮
{
    if(isNetworkPlay == false)      //如果是本地播放
	{
        if(ui->playlist->count() > 1)//如果播放列表不为空
		{
            if(ui->playlist->currentRow()==0)//如果是第一个
                ui->playlist->setCurrentRow(ui->playlist->count()-1); //跳到最后一个
            else                             //如果不是第一个则直接跳到上一个
				ui->playlist->setCurrentRow(ui->playlist->currentRow()-1);
            play(ui->playlist->currentItem()->text());//播放当前选中的上一个视频
            ui->label_PlayArea->clear();     //先清一下屏
			ui->btn_play->setText("暂停");
		}
	}
    else                       //如果是本地播放
	{
        if(ui->playlist_net->count() > 1)   //如果播放列表不为空
		{
            if(ui->playlist_net->currentRow()==0)//如果是第一个
				ui->playlist_net->setCurrentRow(ui->playlist_net->count()-1);
			else
				ui->playlist_net->setCurrentRow(ui->playlist_net->currentRow()-1);
			play(ui->playlist_net->currentItem()->text());
			ui->label_PlayArea->clear();
			ui->btn_play->setText("暂停");
		}
	}
}

void Widget::on_btn_next_clicked()  //如果点击下一首按钮
{
    if(isNetworkPlay == false)      //如果是本地播放
	{
        if(ui->playlist->count() > 1)//如果播放列表不为空
		{
            if(ui->playlist->currentRow()==ui->playlist->count()-1) //如果是最后一首
                ui->playlist->setCurrentRow(0);  //跳到第一个
			else
				ui->playlist->setCurrentRow(ui->playlist->currentRow()+1);
			play(ui->playlist->currentItem()->text());
			ui->label_PlayArea->clear();
			ui->btn_play->setText("暂停");
		}
	}
    else   //如果是网络播放
	{
		if(ui->playlist_net->count() > 1)
		{
			if(ui->playlist_net->currentRow()==ui->playlist_net->count()-1)
				ui->playlist_net->setCurrentRow(0);
			else
				ui->playlist_net->setCurrentRow(ui->playlist_net->currentRow()+1);
			play(ui->playlist_net->currentItem()->text());
			ui->label_PlayArea->clear();
			ui->btn_play->setText("暂停");
		}
	}
}


void Widget::on_btn_setSpeed_clicked()//如果点击了设置速度按钮
{
	double speed=QInputDialog::getDouble(this,"播放速度设置","相对于正常速度倍数:");
	//打开对话框输入播放速度的double值
    if(speed>0)
		p->write(QString("speed_set "+QString::number(speed)+" 2\n").toUtf8());
	//把该速度值转换为字符串形式发给mplayer
}
//声音滑动条移动
void Widget::on_volumeSlider_sliderMoved(int position)
{
	p->write(QString("volume "+QString::number(position)+" 2\n").toUtf8());//把整型值v转换为对应的数字字符串
}
//进度条移动
void Widget::on_processSlider_sliderMoved(int position)
{   //如果当前是在暂停状态
	if(ui->btn_play->text() == QString("播放"))
        p->write(QString("seek "+QString::number(position)+" 2\n").toUtf8()+"pause \n");
    //如果当前是播放状态
    else
		p->write(QString("seek "+QString::number(position)+" 2\n").toUtf8());
}
//从播放器进程接收信息的槽函数
void Widget::dataRecieve()//从mplayer哪里读取播放的一些信息
{
    p->write("get_time_length\n");     //获取文件长度
    p->write("get_time_pos\n");        //获取当前的播放的时间点
    p->write("get_percent_pos\n");     //获取当前进度
    //一行行读取并分析
    while(p->canReadLine())            //如果当前行有数据
	{
        QByteArray b=p->readLine();    //读取一行
        if(b.startsWith("ANS_TIME_POSITION"))//如果以"ANS_TIME_POSITION"开头收到时间位置信息
		{
            b.replace(QByteArray("\n"),QByteArray(""));//把\n替换为空，即把\n删掉
            QString s(b);              //转化为字符串
            currentStr=s.mid(sizeof("ANS_TIME_POSITION"));//取出当前播放经历的时间(秒)
			ui->processSlider->setValue(s.mid(sizeof("ANS_TIME_POSITION")).toFloat());    //从指定的索引位置开始取出字符串,更新播放进度条
		}
        else if((b.startsWith("ANS_LENGTH")))//收到文件总长度(秒)信息
		{
            b.replace(QByteArray("\n"),QByteArray(""));//去掉回车
            QString s(b);             //转化为字符串
			totalTime=s.mid(sizeof("ANS_LENGTH"));//toalTime:"250.86"  int
			int seconds = int(totalTime.toFloat());
            //（1）把秒数转为时分秒
			/*QString a = QString::number(seconds/3600)+":"+
                        QString::number(seconds%3600/60)+":"+
                        QString::number(seconds%60);*/
            //（2）利用时间这个类的处理函数获得总时间（时分秒格式）
            QTime time(0,0,0);             //定义一个0开始的时间
            time = time.addSecs(seconds);  //用秒数初始化这个时间
            QString totalTime2(time.toString("hh:mm:ss"));  //按固定格式转化为时分秒

            time.setHMS(0,0,0);            //重新设置时间为0
            seconds = int(currentStr.toFloat()); //读取当前的秒数
            time = time.addSecs(seconds);  //以当前的秒数初始化时间
			QString currentTime2(time.toString("hh:mm:ss"));

            ui->label_time->setText(currentTime2+"/"+totalTime2); //显示时间进度
			ui->processSlider->setRange(0,s.mid(sizeof("ANS_LENGTH")).toFloat());
			//设置播放进度条的取值范围
		}
        else if((b.startsWith("ANS_PERCENT_POSITION")))//收到位置信息(百分比)
		{
            b.replace(QByteArray("\n"),QByteArray(""));  //去掉\n
            QString s(b);
			currentPercent=s.mid(sizeof("ANS_PERCENT_POSITION"));//取出位置信息
			ui->label_percent->setText("("+currentPercent+"%)");//设置百分比
		}
		QTime currenttime = QTime::currentTime();
        ui->label_out->setText(currenttime.toString("hh:mm:ss"));  //显示当前时间
	}
}

void Widget::on_btn_setTime_clicked()   //点击跳转到固定时间按钮
{
	setTime_Dialog *time_dialog = new setTime_Dialog(this);
	time_dialog->show();
}
//鼠标双击事件
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    static bool isFull = false;  //记录当前是否全屏的状态
    //如果当前不是全屏（双击全屏）
    if(isFull == false)
	{
		isFull = true;
		qDebug()<<event;
        if(event->button()==Qt::LeftButton)
		{
			p->write("vo_full 1\n");
		}
        ui->label_PlayArea->setWindowFlags(Qt::Dialog);//设置显示方式
		ui->label_PlayArea->showFullScreen();
        play(ui->playlist->currentItem()->text());     //播放当前的视频
	}
    //如果当前是全屏（双击恢复原来大小）
	else
	{
		isFull = false;
		qDebug()<<event;
        if(event->button()==Qt::LeftButton)
		{
			p->write("vo_full 1\n");
		}
		//        ui->label_PlayArea->setWindowFlags(Qt::Dialog);
        ui->label_PlayArea->showNormal();  //恢复原来的大小
		ui->label_PlayArea->setWindowFlags(Qt::SubWindow);
		play(ui->playlist->currentItem()->text());

	}
}/*
void MPlayer::fullpushButton_clicked()
{
    process->write("vo_full 1\n");
}*/
//如果点击网络播放按钮
void Widget::on_btn_networkPlay_clicked()
{
    if(timer == NULL && manager == NULL)  //如果是第次打开
	{
        timer = new QTimer(this);   //初始化定时器
        //定时器建立连接（定时获得网络信息）
		connect(timer, SIGNAL(timeout()), this, SLOT(timer_out()));
        timer->start(3000);         //每3秒从网络获取一次数据
		manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
        //建立连接（接收从网络获取到的信息）
        connect(manager, SIGNAL(finished(QNetworkReply* )),
				this, SLOT(replyFinished(QNetworkReply* )));
	}
	isNetworkPlay = true;
	isBtnOrTimer = true;//表示按钮触发
	ui->playlist->setCurrentItem(NULL);
    timer->stop();
	manager->get(QNetworkRequest(QUrl(HTTP_URL+QString(LIST_TXT)))); //发送请求
	timer->start();
}

void Widget::timer_out()     //3秒从网络上获取一次数据
{
    isBtnOrTimer = false;    //表示定时器触发
	manager->get(QNetworkRequest(QUrl(HTTP_URL+QString(LIST_TXT)))); //发送请求
}
//获取网络上发过来的数据
void Widget::replyFinished(QNetworkReply * reply)
{
	QStringList fileNames;
	QTextCodec *codec = QTextCodec::codecForName("utf8");
	//使用utf8编码，这样才可以显示中文
    QString all = codec->toUnicode(reply->readAll());  //获取全部内容
    //QString all = reply->readAll();//把从网络上把下载到的内容读出来
	reply->deleteLater();   //最后要释放reply对象

    fileNames = all.split("\n", QString::SkipEmptyParts); //以“\n”为标志，把一个字符串分成字符串数组
    bool b[3]= {ui->btn_play->isEnabled(), ui->btn_prev->isEnabled(), ui->btn_next->isEnabled()};//保存按钮原来状态
    ui->btn_play->setEnabled(false);   //先禁止使能是哪个按钮
	ui->btn_prev->setEnabled(false);
	ui->btn_next->setEnabled(false);
    QListWidgetItem *ld = ui->playlist_net->currentItem();
    ui->playlist_net->clear();         //清空列表
    ui->playlist_net->addItems(fileNames);//根据网络上获取的信息填充列表

    if(ld != NULL || isBtnOrTimer == true) //如果是点击了网络同步按钮进来的
		ui->playlist_net->setCurrentRow(0);//打开网络列表文件之初设置当前列表项为第一项

    ui->btn_play->setEnabled(b[0]);   //恢复原来的按钮状态
	ui->btn_prev->setEnabled(b[1]);
	ui->btn_next->setEnabled(b[2]);
	//		ui->label_out->setText(fileNames[0]);
}
//双击网络列表的item
void Widget::on_playlist_net_itemDoubleClicked(QListWidgetItem* item)
{
    ui->btn_stop->setEnabled(true);   //使能以下按钮
	ui->btn_prev->setEnabled(true);
	ui->btn_next->setEnabled(true);
	ui->btn_setTime->setEnabled(true);
	ui->btn_setSpeed->setEnabled(true);
	ui->volumeSlider->setEnabled(true);
	ui->processSlider->setEnabled(true);
	isNetworkPlay = true;
    play(item->text());  //播放当前选中的选项
	ui->btn_play->setText("暂停");
}
//单击网络播放列表中的item
void Widget::on_playlist_net_itemClicked(QListWidgetItem* item)
{
	isNetworkPlay = true;
	ui->playlist->setCurrentItem(NULL);
}
//单击本地播放列表中的item
void Widget::on_playlist_itemClicked(QListWidgetItem* item)
{
	isNetworkPlay = false;
	ui->playlist_net->setCurrentItem(NULL);
}
