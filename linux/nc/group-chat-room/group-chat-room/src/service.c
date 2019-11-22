#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LISTENQ 100 //最大监听队列
#define PORT 6000 //监听端口
#define MAXFD 100 //最大的在线用户数量
#define NAMESIZE 20 //客户端姓名占用的字节数
#define TIMESIZE 30 //收到消息时的时间占用的字节数
#define SENDBUFSIZE 1024 //消息的数组长度
#define FILENAMESIZE 40 //聊天记录文件名的长度
#define NEWCLIENTINFORMSIZE 70 //通知新用户上线的消息数组长度
int sockfd = 0; //绑定服务器端的 ip 地址和端口的套接字
FILE * fp; //文件指针，用于指向保存聊天记录的文件
int maxi = 0; //maxi 表示当前 client 数组中最大的用户的 i 值
static int client[MAXFD]; //全局数组，保存所有客户端对应的套接口描述符
void tcp_init(int argc, char * argv[])
{
	struct sockaddr_in server_addr;
	if (argc != 1)
	{
		fprintf(stderr, "Usage:%s portnumber\a\n", argv[0]);
		exit(1);
	}
	/* 服务器端开始建立 socket 描述符 */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Socket error:%s\n\a", strerror(errno));
		exit(1);
	}
	/* 服务器端填充 sockaddr 结构 */
	bzero(&server_addr, sizeof(struct sockaddr_in));//内存空间初始化
	server_addr.sin_family = AF_INET;//协议
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//IP号（htonl(INADDR_ANY)自动获取本机的IP号）
	server_addr.sin_port = htons(PORT);////端口号
	int reuse = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *) & reuse, sizeof(int));
	/* 捆绑 sockfd 描述符 */
	if (bind(sockfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1)
	{
		fprintf(stderr, "Bind error:%s\n\a", strerror(errno));
		exit(1);
	}
	printf("服务器监听端口 %d...\n", PORT);
	/* 监听 sockfd 描述符 */
	if (listen(sockfd, LISTENQ) == -1)
	{
		fprintf(stderr, "Listen error:%s\n\a", strerror(errno));
		exit(1);
	}
}
void recv_and_send_to_all_client(int index)
{
	int nbytes = 0;
	char sendbuf[SENDBUFSIZE] = {0};//发送消息的缓冲区1024
	int outindex = 0;
	time_t tt;
	struct tm * pTm;
	nbytes = 0;
	nbytes = read(client[index], sendbuf, sizeof(sendbuf));
	sendbuf[0] = 'M'; //'M'表示正常聊天信息
	if (nbytes > 0)
	{
		tt = time(NULL);
		pTm = localtime(&tt);
		//sendbuf的第二十位写时间
		sprintf(sendbuf + NAMESIZE, " %d-%d-%d %0d:%0d:%0d\n", (1900 + pTm->tm_year), (1 + pTm->tm_mon), (pTm->tm_mday), (pTm->tm_hour), (pTm->tm_min), (pTm->tm_sec));
		outindex = 0;
	/*以下循环将消息转发给所有客户端*/
		while (outindex < maxi)
		{
			if (write(client[outindex], sendbuf, sizeof(sendbuf)) == -1)
			{
				fprintf(stderr, "Write Error:%s\n", strerror(errno));
				close(sockfd);
				fclose(fp);
				exit(1);
			}
			outindex++;
		}
		/*如果某个客户端下线，则删除全局数组 client 中对应的套接字*/
		if (strcmp(sendbuf + NAMESIZE + TIMESIZE, "QUIT") == 0 || strcmp(sendbuf + NAMESIZE +TIMESIZE, "Quit") == 0|| strcmp(sendbuf + NAMESIZE + TIMESIZE, "quit") == 0)
		{
			for (; index < maxi - 1; index++)
			client[index] = client[index + 1];
			maxi--;
		}
/*服务器打印出消息内容并保存消息到文件*/
		printf("%s", sendbuf + 1);
		printf("%s", sendbuf + NAMESIZE);
		printf(" %s\n", sendbuf + NAMESIZE + TIMESIZE);
		fprintf(fp, "%s", sendbuf + 1);
		fprintf(fp, "%s", sendbuf + NAMESIZE);
		fprintf(fp, "%s\n", sendbuf + NAMESIZE + TIMESIZE);
	}
}
void * check_client_send(void * arg) //监听转发线程入口函数
{
	static int index = 0;//very important
	int select_n = 0;
	int in = 0;
	fd_set allset, rset;

//将指定的文件描述符集清空，在对文件描述符集合进行设置前，必须对其进行初始化，如果不清空，由于在系统分配内存空间后，通常并不作清空处理，所以结果是不可知的
	FD_ZERO(&allset);
	while (1)
	{
		if (maxi > 0)
		{
			for (index = 0; index < maxi; index++)
			FD_SET(client[index], &allset);//用于在文件描述符集合中增加一个新的文件描述符
			rset = allset;
			select_n = select(FD_SETSIZE, &rset, NULL, NULL, NULL);//阻塞监听所有的客户端对应的
			switch (select_n)
			{
				case 0:continue;
				case -1:
				perror("select error!");
				exit(-1);
				default:
				for (index = 0, in = 0; index < maxi && in < select_n; index++)
				if (FD_ISSET(client[index], &rset)) //用于测试指定的文件描述符是否在该集合中
				{
					in++;
					recv_and_send_to_all_client(index);//调用函数接收客户端的消息
				}
			}
		}
	}
}
/*该线程等待客户端连接，并将新的套接字存入全局数组 static int client[MAXFD]中*/
void * wait_client_connect(void * pthidcheck)
{
	struct sockaddr_in client_addr;
	int sin_size, portnumber;
	int new_fd = 0;
	char clientname[NAMESIZE] = {0};//客户端姓名占用的字节数20
	char new_client_inform[NEWCLIENTINFORMSIZE] = {0};//通知新用户上线的消息数组长度70
	static int index = 0;
	time_t tt;
	struct tm * pTm = NULL;
	while (1)
	{
		/* 服务器阻塞,直到客户程序建立连接 */
		if (maxi >= MAXFD)//maxi开始是0,MAXFD是100
		{
			printf("已经达到人数上线\n");
			continue;
		}
		sin_size = sizeof(struct sockaddr_in);
		if ((new_fd = accept(sockfd, (struct sockaddr *)(&client_addr), &sin_size)) == -1)//建立连接(没有客户端连接就阻塞在这里)
		{
			fprintf(stderr, "Accept error:%s\n\a", strerror(errno));
			exit(1);
		}
		client[maxi] = new_fd;//建立连接成功之后把客户端的通信套接字存储在数组中的第一位
		if (-1 == read(client[maxi], clientname, sizeof(clientname)))
		{
			fprintf(stderr, "Read client name error:%s\n", strerror(errno));
			close(sockfd);
			exit(1);
		}
		maxi++;//(第一次maxi=1)
		tt = time(NULL);
		pTm = localtime(&tt);//获取本地时间
		sprintf(new_client_inform, "N%d-%d-%d %0d:%0d:%0d", (1900 + pTm->tm_year), (1 + pTm->tm_mon), (pTm->tm_mday), (pTm->tm_hour), (pTm->tm_min), (pTm->tm_sec)); //'N'表示向所有在线
		//在数组的第三十位存储新用户 %s 进入聊天室消息
		sprintf(new_client_inform + TIMESIZE, " 新用户 %s 进入聊天室", clientname);
		int outindex = 0;
		while (outindex < maxi) //向聊天室中所有的客户通知新用户上线
		{
			if (write(client[outindex], new_client_inform, sizeof(new_client_inform)) == -1)
			{
				fprintf(stderr, "Write Error:%s\n", strerror(errno));
				close(sockfd);
				exit(1);
			}
			outindex++;
		}
		/*创建线程收客户端的消息并转发给所有其它在线客户端，同时保存聊天记录*/
		if (maxi == 1)
		{
			if (-1 == pthread_create((pthread_t *)pthidcheck, NULL, check_client_send, NULL))
			{
				fprintf(stderr, "Creat pthread Error:%s\n", strerror(errno));
				close(sockfd);
				exit(1);
			}
			fp = fopen("server_msgrecord.txt", "ab");
			if (fp == NULL)
			{
				fprintf(stderr, "Fopen Error:%s\a\n", strerror(errno));
				close(sockfd);
				exit(1);
			}
		}
		else if (maxi > 1)
		{
			pthread_cancel(*(pthread_t *)pthidcheck);//取消一个还没有运行完的线程
			if (-1 == pthread_create((pthread_t *)pthidcheck, NULL, check_client_send, NULL))
			{
					fprintf(stderr, "Creat pthread Error:%s\n", strerror(errno));
					fclose(fp);
					close(sockfd);
					exit(1);
			}
		}
		//打印每连接一个客户端的名字和时间
		printf("%s\n", new_client_inform + 1);//打印客户端连接的时间
		printf("%s\n", new_client_inform + TIMESIZE);//新用户 %s 进入聊天室
	    fprintf(fp, "%s\n", new_client_inform + 1);
		fprintf(fp, "%s\n", new_client_inform + TIMESIZE);
	}
}
int main(int argc, char * argv[])
{
		pthread_t thidaccept, thidcheck = -1;//定义两个线程id
		tcp_init(argc, argv);
		printf("欢迎来到本聊天室\n");
		/*创建线程等待接受客户端连接请求*/
		if (-1 == pthread_create(&thidaccept, NULL, wait_client_connect, (void *) & thidcheck))
		{
			fprintf(stderr, "Creat pthread Error:%s\n", strerror(errno));
			close(sockfd);
			exit(1);
		}
		pthread_join(thidaccept, NULL);//用来等待这个thidaccept线程结束
		if (thidcheck != -1)
		pthread_join(thidcheck, NULL);
		close(sockfd);
		fclose(fp);
		exit(0);
}

