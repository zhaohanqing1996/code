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

#define PORT 8888
#define BUFSIZE 32
#define SENDBUFSIZE 1024
#define NAMESIZE 16
#define FILENAMESIZE 32
#define IP "127.0.0.1"

void connect_service(void);
void *recv_from_service(void *argc);
void *send_to_service(void *argc);

static int socket_fd;
//char file_name[FILENAMESIZE]={0};
char name[NAMESIZE]={0};
char buf[BUFSIZE]={0};
char sendbuf[SENDBUFSIZE]={0};
char recvbuf[SENDBUFSIZE]={0};
FILE *fd;

int main(int argc,char *argv[])
{
    pthread_t pthread_recv,pthread_send;
    connect_service();
    /* strcpy(file_name,name);
    strcat(file_name,"_msg");
    fd = fopen(file_name,"a+");
    if(fd == NULL)
    {
        fprintf(stderr,"创建或打开文件失败：%s\n",strerror(errno));
        exit(1);
    } */
    int pthread_ret_1 = pthread_create(&pthread_recv,NULL,recv_from_service,NULL);
    if(pthread_ret_1 == -1)
    {
        fprintf(stderr,"线程recv_from_service创建失败：%s\n",strerror(errno));
        exit(1);
    }
    printf("线程recv_from_service创建成功\n");
    int pthread_ret_2 = pthread_create(&pthread_send,NULL,send_to_service,NULL);
    if(pthread_ret_2 == -1)
    {
        fprintf(stderr,"线程send_to_service创建失败：%s\n",strerror(errno));
        exit(1);
    }
    printf("线程send_to_service创建成功\n");
    pthread_join(pthread_recv, NULL);
	pthread_join(pthread_send, NULL);
	close(socket_fd);
	exit(0);
}

void connect_service(void)
{
    struct sockaddr_in service_addr;
    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        fprintf(stderr,"创建通信套接字出错：%s\n",strerror(errno));
        exit(1);
    }
    printf("创建监听套接字成功！\n");

    service_addr.sin_addr.s_addr = inet_addr(IP);
    service_addr.sin_family = AF_INET;
    service_addr.sin_port = htons(PORT);
    printf("绑定服务器地址成功！\n");

    int connect_ret = connect(socket_fd,(struct sockaddr *)&service_addr,sizeof(service_addr));
    if(connect_ret == -1)
    {
        fprintf(stderr,"连接服务器出错：%s\n",strerror(errno));
        exit(1);
    }
    printf("连接服务器成功！\n欢迎来到聊天室！\n请输入你的昵称：\n>");

    fgets(name,sizeof(name),stdin);
    size_t send_ret = send(socket_fd,name,sizeof(name),0);
    if(send_ret == -1)
    {
        fprintf(stderr,"向服务器发送消息失败：%s\n",strerror(errno));
        close(socket_fd);
        exit(1);
    }
    //printf("登录成功！\n");
}

void *recv_from_service(void *argc)
{
    while(1)
    {
        size_t recv_ret = recv(socket_fd,recvbuf,sizeof(recvbuf),0);
        if(recv_ret  == -1)
        {
            fprintf(stderr,"接受服务器消息出错：%s\n",strerror(errno));

        }
        printf("%s\n",recvbuf);

        /* ssize_t write_ret = write(*(int *)fd,recvbuf,sizeof(recvbuf));
        if(write_ret == -1)
        {
            fprintf(stderr,"保存聊天信息失败：%s\n",strerror(errno));
            fclose(fd);
            close(socket_fd);
            exit(1);
        } */
        //fprintf(fd,"%s\n",recvbuf);
    }
}

void *send_to_service(void *argc)
{
    time_t tt;
	struct tm * pTm;
    while(1)
    {
        memset(sendbuf, 0, sizeof(sendbuf));
		tt = time(NULL);
		pTm = localtime(&tt);//获得本地的时间
        printf(">");
        fscanf(stdin,"%s",sendbuf);

        if(strcmp(sendbuf,"QUIT")==0 || strcmp(sendbuf,"Quit")==0 || strcmp(sendbuf,"quit")==0)
        {
            printf("你已退出聊天室\n");
            close(socket_fd);
            exit(1);
        }

		sprintf(buf,"%s%d-%d-%d %0d:%0d:%0d\n",name,(1900 + pTm->tm_year), (1 + pTm->tm_mon),(pTm->tm_mday), (pTm->tm_hour), (pTm->tm_min), (pTm->tm_sec));
        strcat(buf,sendbuf);

        size_t send_ret = send(socket_fd,buf,sizeof(sendbuf)+sizeof(buf),0);
        if(send_ret == -1)
        {
            fprintf(stderr,"向服务器发送消息失败：%s\n",strerror(errno));
            close(socket_fd);
            exit(1);
        }
    }
}
