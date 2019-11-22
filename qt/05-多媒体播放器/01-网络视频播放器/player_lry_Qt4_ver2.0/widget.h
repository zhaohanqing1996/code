#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QFile>
#include <QtNetwork>
#include <QUrl>
#include <QTextCodec>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QSpacerItem>

#define LIST_TXT "list.txt"
#define HTTP_URL "http://192.168.1.199/MediaFiles/"    //http的URL前面一部分

namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::Widget *ui;

	QString currentStr;
	QString currentPercent;
	QString totalTime;
	QString fileName;
	QTimer * timer;
	bool isNetworkPlay;
	bool isBtnOrTimer;
	QNetworkAccessManager *manager;

	void play(QString fileName);
private slots:
 void timer_out();
	void on_playlist_itemClicked(QListWidgetItem* item);
	void on_playlist_net_itemClicked(QListWidgetItem* item);
	void on_playlist_net_itemDoubleClicked(QListWidgetItem* item);
	void on_btn_networkPlay_clicked();
	void on_btn_setTime_clicked();
	void on_processSlider_sliderMoved(int position);
	void on_volumeSlider_sliderMoved(int position);
	void on_btn_setSpeed_clicked();
	void on_btn_next_clicked();
	void on_btn_prev_clicked();
	void on_btn_stop_clicked();
	void on_btn_play_clicked();
	void on_playlist_itemDoubleClicked(QListWidgetItem* item);
	void on_btn_del_clicked();
	void on_btn_add_clicked();

	void dataRecieve();
	void replyFinished(QNetworkReply * reply);

protected:
	void mouseDoubleClickEvent(QMouseEvent * event );
};

#endif // WIDGET_H
