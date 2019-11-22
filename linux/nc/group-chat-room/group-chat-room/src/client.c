#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define PORT 6000 //监听端口
#define NAMESIZE 20 //客户端姓名占用的字节数
#define TIMESIZE 30 //收到消息时的时间占用的字节数
#define SENDBUFSIZE 1024 //消息的数组长度
#define FILENAMESIZE 40 //聊天记录文件名的长度
#define NEWCLIENTINFORMSIZE 70 //通知新用户上线的消息数组长度
FILE * fp; //文件指针，用于指向保存聊天记录的文件
static int sockfd; //绑定服务器端的 ip 地址和端口的套接字
char clientname[NAMESIZE] = {0}; //保存自己的昵称20
/*连接服务器*/
void connect_server()
{
	struct sockaddr_in server_addr;
	struct hostent * host;
	char strhost[16];
	printf("请输入服务器 ip 地址\n");
	scanf("%s", strhost);
	//strcpy(strhost, "192.168.0.101");
	if ((host = gethostbyname(strhost)) == NULL)
	{
		fprintf(stderr, "Gethostname error\n");
		exit(1);
	}
	/* 客户程序开始建立 sockfd 描述符 */
	printf("正在建立套接口 ...\n");
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Socket Error:%s\a\n", strerror(errno));
		exit(1);
	}
	/* 客户程序填充服务端的资料 */
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	printf("套接口创建成功，正在连接服务器...\n");
	/* 客户程序发起连接请求 */
	if (connect(sockfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1)
	{
		fprintf(stderr, "Connect Error:%s\a\n", strerror(errno));
		close(sockfd);
		exit(1);
	}
	/* 连接成功了 */
	printf("连接服务器成功\n 欢迎来到聊天室\n");
	printf("请输入你的用户呢称\n>");
	fflush(stdout);
	scanf("%s", clientname);
	write(sockfd, clientname, sizeof(clientname));//向服务器客户名字的发送消息
	char recvbuf[SENDBUFSIZE] = {0};//消息的数组长度1024
	//读取服务器发送的消息
	if (-1 == read(sockfd, recvbuf, sizeof(recvbuf)))
	{
		fprintf(stderr, "Read my inform Error:%s\n", strerror(errno));
		close(sockfd);
		exit(1);
	}
	if (recvbuf[0] == 'N')
	{
		char filename[FILENAMESIZE] = {0}; //40 聊天记录文件名的长度
		strcpy(filename, clientname);//将客户得姓名复制到filename数组中
		strcat(filename, "_msgrecord.txt");//连接客户的名字和_msgrecord.txt
		fp = fopen(filename, "ab");//用客户的名字和_msgrecord.txt建立文件
		if (fp == NULL)
		{
			fprintf(stderr, "Fopen Error:%s\a\n", strerror(errno));
			close(sockfd);
			exit(1);
		}
		printf("%s\n", recvbuf + 1);//打印服务器发送过来的时间
		printf("%s\n", recvbuf + TIMESIZE);//打印新用户 %s 进入聊天室
		fprintf(fp, "%s\n", recvbuf + 1);
		fprintf(fp, "%s\n", recvbuf + TIMESIZE);
		printf("开始聊天吧（ \"QUIT\"断开连接） \n");
	}
}
/*接收服务器消息线程入口函数*/
void * recvfromserver(void * arg)
{
	time_t tt;
	struct tm * pTm;
	char recvbuf[SENDBUFSIZE];//定义一个用于接收消息的数组长度1024
	int nbytes = 0;
	while (1)
	{ 
		memset(recvbuf, 0, sizeof(recvbuf));
		if (0 < read(sockfd, recvbuf, sizeof(recvbuf)))
		{
			if (recvbuf[0] == 'M') //如果消息是‘ M’表示消息收到服务器的正常聊天消息
			{
				fprintf(fp, "\n%s", recvbuf + 1);
				fprintf(fp, " %s", recvbuf + NAMESIZE);
				fprintf(fp, " %s", recvbuf + NAMESIZE + TIMESIZE);
				fflush(fp);//fflush(fp)是将文件缓存中的数据刷到磁盘
//如果不执行fflush，则如果操作系统崩溃或者主机掉电，你通过fp写的内容有可能会丢失
				if (strcmp(recvbuf + 1, clientname) == 0)
				continue;
				printf("\n%s", recvbuf + 1);
				printf(" %s", recvbuf + NAMESIZE);
				printf(" %s", recvbuf + NAMESIZE + TIMESIZE);
			}
			else if (recvbuf[0] == 'N') //如果是‘ N’表示收到服务器的新用户通知上线消息
			{
				printf("%s\n", recvbuf + 1);
				printf("%s\n", recvbuf + TIMESIZE);
				fprintf(fp, "%s\n", recvbuf + 1);
				fprintf(fp, "%s\n", recvbuf + TIMESIZE);
			}
			else
			printf("收到不能识别的信息\n");
			/*显示时间*/
			tt = time(NULL);
			pTm = localtime(&tt);
			printf("\n%s %d-%d-%d %0d:%0d:%0d\n>", clientname, (1900 + pTm->tm_year), (1 + pTm->tm_mon), (pTm->tm_mday), (pTm->tm_hour), (pTm->tm_min), (pTm->tm_sec));
			fflush(stdout);
		}
	}
}
/*向服务器发送消息线程入口函数*/
void * sendtoserver(void * arg)
{
	time_t tt;
	struct tm * pTm;
	char sendbuf[SENDBUFSIZE];//定义一个用于发送消息的数组长度为1024
	//sendbuf数组的第五十位开始存储输入的信息
	//fgets(sendbuf + NAMESIZE + TIMESIZE, sizeof(sendbuf) - NAMESIZE + TIMESIZE, stdin);
	//清除输入缓
	while (1)
	{
		memset(sendbuf, 0, sizeof(sendbuf));
		tt = time(NULL);
		pTm = localtime(&tt);//获得本地的时间
		printf("%s %d-%d-%d %0d:%0d:%0d\n>", clientname, (1900 + pTm->tm_year), (1 + pTm->tm_mon),(pTm->tm_mday), (pTm->tm_hour), (pTm->tm_min), (pTm->tm_sec));
		fflush(stdin);
		fflush(stdout);
		fgets(sendbuf + NAMESIZE + TIMESIZE, sizeof(sendbuf)-NAMESIZE + TIMESIZE, stdin);
		sendbuf[49 + strlen(sendbuf + NAMESIZE + TIMESIZE)] = '\0';
		strcpy(sendbuf + 1, clientname);//在消息前面加上自己的呢称
		if ((write(sockfd, sendbuf, sizeof(sendbuf))) == -1)
		{
			fprintf(stderr, "Write Error:%s\n", strerror(errno));
			close(sockfd);
			fclose(fp);
			exit(1);
		}
		/*如果输入“ quit”或“ Quit"或“ QUIT”都会退出*/
		if (strcmp(sendbuf + NAMESIZE + TIMESIZE, "QUIT") == 0 || strcmp(sendbuf + NAMESIZE +
		TIMESIZE, "Quit") == 0 || strcmp(sendbuf + NAMESIZE + TIMESIZE, "quit") == 0)
		{
			close(sockfd);
			fclose(fp);
			printf("您已退出聊天室\n");
			exit(1);
		}
	}
}
int main(int argc, char * argv[])
{
	pthread_t thidrcv, thidsnd;
	//定义两个线程id 一个用于接收服务器的消息，一个用于向服务器发送消息
	connect_server(); //连接服务器
	/*创建发送和接收消息的线程*/
	if (-1 == pthread_create(&thidrcv, NULL, recvfromserver, NULL))
	{
		fprintf(stderr, "Creat pthread Error:%s\n", strerror(errno));
		close(sockfd);
		exit(1);
	}
	if (-1 == pthread_create(&thidsnd, NULL, sendtoserver, NULL))
	{
		fprintf(stderr, "Creat pthread Error:%s\n", strerror(errno));
		close(sockfd);
		fclose(fp);
		exit(1);
	}
	pthread_join(thidrcv, NULL);
	pthread_join(thidsnd, NULL);
	close(sockfd);
	fclose(fp);
	exit(0);
}

