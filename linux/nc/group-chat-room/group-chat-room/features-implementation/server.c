/******* 服务器程序 (server.c) ************/
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LISTENQ 3 //最大监听队列
#define PORT 6000 //监听端口
#define NAMESIZE 20 //客户端姓名占用的字节数
#define SENDBUFSIZE 1024 //消息的数组长度
int sockfd; //绑定服务器端的 ip 地址和端口的套接字
int maxi = 0; //maxi 表示当前 client 数组中最大的用户的 i 值
static int client[LISTENQ]; //全局数组，保存所有客户端对应的套接口描述符

void tcp_init()
{
	struct sockaddr_in server_addr;
	/* 服务器端开始建立 socket 描述符 */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Socket error:%s\n\a", strerror(errno));
		exit(1);
	}
	/* 服务器端填充 sockaddr 结构 */
	bzero(&server_addr, sizeof(struct sockaddr_in));//清空
	server_addr.sin_family = AF_INET;//自动填充本地IP
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);
	int reuse = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *) & reuse, sizeof(int));//socket允许重用
	/* 捆绑 sockfd 描述符 */
	if (bind(sockfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1)
	{
		fprintf(stderr, "Bind error:%s\n\a", strerror(errno));
		exit(1);
	}
	printf("服务器监听端口%d...\n", PORT);
	/* 监听 sockfd 描述符 */
	if (listen(sockfd, LISTENQ) == -1)
	{
		fprintf(stderr, "Listen error:%s\n\a", strerror(errno));
		exit(1);
	}
}


int main()
{
	char sendbuf[SENDBUFSIZE];
	int new_fd,nbytes,i;
	int select_n = 0,sin_size;
	struct sockaddr_in client_addr;
	fd_set allset;
	tcp_init();
	
	for(i=0;i<3;i++)//等待客户端连接，3个客户端全部连接之后开始通信
	{
	if ((new_fd = accept(sockfd, (struct sockaddr *)(&client_addr), &sin_size)) == -1)
		{
			fprintf(stderr, "Accept error:%s\n\a", strerror(errno));
			exit(1);
		}
		client[maxi] = new_fd;
		maxi++;
		printf ("client %s:%d is connected!\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	}
	printf("欢迎来到本聊天室\n");
	strcpy(sendbuf, "系统消息");
	strcpy(sendbuf+NAMESIZE, "欢迎来到本聊天室");
	for(i=0;i<maxi;i++)
		write(client[i], sendbuf, sizeof(sendbuf));

	
//用IO多路转换实现同时等待多个客户端发送消息。
	FD_ZERO(&allset);
	while (1)
	{
		if (maxi > 0)
		{
			for (i = 0; i < maxi; i++)
				FD_SET(client[i], &allset);

			select_n = select(FD_SETSIZE, &allset, NULL, NULL, NULL);/*阻塞监听所有的客户端对应的套
			接字有没有可读的，即是否有人发消息过来*/
			switch (select_n)
			{ 
				case 0:continue;
				case -1:
				perror("select error!");
				exit(-1);
				default:
				for (i = 0; i < maxi; i++)
				if (FD_ISSET(client[i], &allset))
				{
					nbytes = read(client[i], sendbuf, sizeof(sendbuf));
					if (nbytes > 0)
					{
							if (write(client[i], sendbuf, sizeof(sendbuf)) == -1)
							{
								fprintf(stderr, "Write Error:%s\n", strerror(errno));
								close(sockfd);
								exit(1);
							} 
						/*服务器打印出消息*/
						printf("%s\n", sendbuf);
						printf("%s\n\n", sendbuf + NAMESIZE);
					}
				}
			}
		}
	}
	close(sockfd);
	exit(0);
}


