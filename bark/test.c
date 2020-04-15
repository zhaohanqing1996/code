#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>

char *str;
char buf[4096];

int obtainMessage(void);
void postHttpMessage(void);
int connectPushServer(void);
int sendMessageToServer(void);

int main(int argc,char* argv[])
{
    obtainMessage();
    postHttpMessage();
    sendMessageToServer();
    return 0;
}

int obtainMessage(void)
{
    str = malloc(256);
    if(str == NULL)
    {
        perror("malloc");
        return -1;
    }
    printf("请输入推送信息：\n");
    scanf("%s",str);
    return 0;
}

void postHttpMessage(void)
{
    memset(buf,0,4096);

    sprintf(buf,"POST http://api.day.app/seFqfLJGHTWDvXnGZPYeRP/%s HTTP/1.1\r\n",str);
    strcat(buf,"Host: api.day.app\r\n");
    strcat(buf,"Content-Length: 0\r\n");
    strcat(buf,"\r\n\r\n");

    printf("%s\n",buf);
}

int connectPushServer(void)
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
    return sock_fd;
}

int sendMessageToServer(void)
{
    char recv_buf[4096];
    ssize_t send_num,recv_num;
    int fd = connectPushServer();
    send_num = send(fd,buf,strlen(buf),0);
    if(send_num < 0)
    {
        perror("send");
        return -1;
    }
    printf("成功发送信息到推送服务器！\n");

    recv_num = recv(fd,recv_buf,sizeof(recv_buf),0);
    if(recv_num < 0)
    {
        perror("recv");
        return -1;
    }
    printf("收到推送服务器信息: \n%s\n",recv_buf);
    return 0;
}