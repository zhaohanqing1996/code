#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>

char *str;
char *obtainPushMessage(void);
void connectPushServer(void);

int main(int argc,char* argv[])
{
    pushMeobtainPushMessagessage();
    connectPushServer();
    free(str);
    return 0;
}

char *obtainPushMessage(void)
{
    str = malloc(512);
    if(str == NULL)
    {
        perror("malloc");
        return -1;
    }
    printf("请输入推送信息：\n");
    scanf("%s",str);
    return 0;
}

void connectPushServer(void)
{
    int sock_fd;
    struct sockaddr_in sockaddr_server;
    struct hostent* hostInfo;

    printf("正在连接服务器...\n");
    sock_fd = socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd < 0)
    {
        perror("socket");
        return -1;
    }
    printf("创建套接字成功!\n");

    hostInfo = gethostbyname("api.day.app");
    if(hostInfo == NULL)
    {
        printf("获取服务器信息失败！\n");
        return -1;
    }
    printf("获取服务器信息成功！\n");

    memset(&sockaddr_server,0,sizeof(sockaddr_server));
    sockaddr_server.sin_family = AF_INET;
    sockaddr_server.sin_port = (htons(80));

    printf("Server IP = %s\n",inet_ntoa(*((struct in_addr *)hostInfo->h_name)));

    memcpy(&sockaddr_server.sin_addr,(hostInfo->h_addr_list[0]),hostInfo->h_length);

    if(connect(sock_fd,(struct sockaddr *)&sockaddr_server,sizeof(sockaddr_server)) < 0)
    {
        perror("connect");
        return -1;
    }
    printf("连接服务器成功！\n");
}

void pushMessageToBark(void)
{
    
}