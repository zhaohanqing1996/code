	此版本的Qt网络视频播放器需要Linux虚拟机事先配置好http服务器，并且播放器固定读取http服务器上的多媒体音视频文件，所以在http服务器的文件共享目录(/var/www/html)下有多媒体文件。
	不同人的主机ip地址以及http配置可能会不同，则需要修改源文件widget.h中的这两个宏：
#define LIST_TXT "list.txt" 	//服务器存放多媒体文件名的文件
#define HTTP_URL "http://192.168.1.199/MediaFiles/"    //http的URL前面一部分
	把它们修改为自己对应的文件名及ip地址和网络路径即可。
