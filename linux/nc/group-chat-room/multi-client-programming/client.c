#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define PORT    9999 //端口号
int main()
{
    int sd, ret;
    char buf[1024] = {};
    struct sockaddr_in ser_addr;
    socklen_t len = sizeof(ser_addr);
    sd = socket(AF_INET,SOCK_STREAM, 0); 
	if(sd<0)
	{
		perror("socket");
		return -1;
	}
   //设置sockaddr_in结构体中相关参数*/
    ser_addr.sin_family =  AF_INET;          //Internet
    ser_addr.sin_port   =  htons(PORT);     
	ser_addr.sin_addr.s_addr  = inet_addr("192.168.15.2"); //把IP地址，以字符串转换成整形
    ret = connect(sd, (struct sockaddr *)&ser_addr, len);//连接服务器

    char ab[1024]={0};
	printf("connect ok!\n");
    while(1)
	{
		scanf("%s",ab);
		fflush(stdin);
		write(sd,ab,strlen(ab)+1);
    }
    printf("wrong\n");
    close(sd);
    return 0;
}
