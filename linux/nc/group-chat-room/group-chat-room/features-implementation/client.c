#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define PORT 6000 //监听端口
#define NAMESIZE 20 //客户端姓名占用的字节数
#define SENDBUFSIZE 1024 //消息的数组长度

static int sockfd; //绑定服务器端的 ip 地址和端口的套接字
char clientname[NAMESIZE] = {0}; //保存自己的昵称

/*连接服务器*/
void connect_server()
{
	char recvbuf[SENDBUFSIZE];
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
	printf("正在建立套接口...\n");
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
	printf("等待其他用户连接\n");
	if (0 < read(sockfd, recvbuf, sizeof(recvbuf)))//等待服务器回复消息
		{
			printf("\n%s\n", recvbuf);
			printf("%s\n", recvbuf + NAMESIZE);
		}
	getchar();//过滤‘\n’
}

int main()
{
	char sendbuf[SENDBUFSIZE];
	char recvbuf[SENDBUFSIZE];
	pthread_t thidrcv, thidsnd;
	connect_server(); //连接服务器
	while (1)
	{
		memset(sendbuf, 0, sizeof(sendbuf));
		printf("\n>");
		//scanf("%s",sendbuf+NAMESIZE);
		//gets(sendbuf+NAMESIZE);
		fgets(sendbuf + NAMESIZE, sizeof(sendbuf)-NAMESIZE, stdin);
		strcpy(sendbuf, clientname);//在消息前面加上自己的呢称
		if ((write(sockfd, sendbuf, sizeof(sendbuf))) == -1)
		{
			fprintf(stderr, "Write Error:%s\n", strerror(errno));
			close(sockfd);
			exit(1);
		}
		/*如果输入“ QUIT”退出*/
		if (strcmp(sendbuf + NAMESIZE, "QUIT") == 0)
		{
			close(sockfd);
			printf("您已退出聊天室\n");
			exit(1);
		}

		memset(recvbuf, 0, sizeof(recvbuf));

		if (0 < read(sockfd, recvbuf, sizeof(recvbuf)))
		{
			printf("\n%s\n", recvbuf);
			printf("%s\n", recvbuf + NAMESIZE);
		}
	}
	close(sockfd);
	exit(0);
}

