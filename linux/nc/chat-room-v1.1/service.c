#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <pthread.h>
#include <semaphore.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/poll.h>

#define PORT 8888
#define LISTENQ 100                     //最大监听队列
#define MAXFD 100                       //最大在线用户数
#define SENDBUFSIZE 1024                //发送消息缓存区字节大小
#define NAMESIZE 16
#define IP "127.0.0.1"

void tcp_init(int argc,char *argv[]);
void *check_client_send(void *argc);
void *wait_client_connect(void *argc);
void recv_and_send_to_all_client(int argc);

int service_socket_fd;
int current_max_num=0;                      //当前最大用户的值
static char sendbuf[SENDBUFSIZE]={0};       //保存要发送的数据
static int client[MAXFD]={0};               //全局数组，保存客户端对应套接字描述符
static char name[NAMESIZE]={0};             //保存客户端昵称
pthread_t wait_connect_thid,check_send_thid;
FILE *fd;

int main(int argc,char *argv[])
{
    tcp_init(argc,argv);

    int pthread_ret1 = pthread_create(&wait_connect_thid,NULL,wait_client_connect,NULL);
    if(pthread_ret1 == -1)
    {
        fprintf(stderr,"创建线程wait_connect_thid失败：%s\n",strerror(errno));
        close(service_socket_fd);
        exit(1);
    }

    pthread_join(wait_connect_thid,NULL);
    if(pthread_ret1 == -1)
    {
        pthread_join(check_send_thid,NULL);
    } 
    fclose(fd);
    close(service_socket_fd);
    exit(0);
}

void tcp_init(int argc,char *argv[])
{
    struct sockaddr_in service_addr;

    if(argc != 1)
    {
        fprintf(stderr,"Usage:%s portnumber\n",argv[0]);
        exit(1);
    }

    service_socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(service_socket_fd == -1)
    {
        fprintf(stderr,"创建监听套接字出错：%s\n",strerror(errno));
        exit(1);
    }
    printf("创建监听套接字成功！\n");

    bzero(&service_addr,sizeof(service_addr));              //初始化内存空间
    //service_addr.sin_addr.s_addr = htonl(INADDR_ANY);       //自动获取本机ip地址
    service_addr.sin_addr.s_addr = inet_addr(IP);
    service_addr.sin_family = AF_INET;
    service_addr.sin_port = htons(PORT);

    int bind_ret = bind(service_socket_fd,(struct sockaddr *)&service_addr,sizeof(service_addr));
    if(bind_ret == -1)
    {
        fprintf(stderr,"绑定服务器ip失败：%s\n",strerror(errno));
        exit(1);
    }
    printf("绑定服务器ip成功！\n");

    int listen_ret = listen(service_socket_fd,LISTENQ);
    if(listen_ret == -1)
    {
        fprintf(stderr,"监听出错：%s\n",strerror(errno));
        exit(1);
    }
    printf("服务器正在监听，等待客户端连接...\n");
}

void *wait_client_connect(void *argc)
{
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    while(1)
    {
        int client_socket_fd = accept(service_socket_fd,(struct sockaddr *)&client_addr,&addr_len);
        if(client_socket_fd == -1)
        {
            fprintf(stderr,"接受客户端连接失败：%s\n",strerror(errno));
            exit(1);
        }
        printf("新的客户端:%d已连接\n",client_socket_fd);
        client[current_max_num] = client_socket_fd;                     //将客户端描述符保存在数组对应位置中

        /*等待客户端发送客户端昵称*/
        ssize_t recv_ret = recv(client[current_max_num],name,sizeof(name),0);
        if(recv_ret == -1)
        {
            fprintf(stderr,"获取客户端昵称失败：%s\n",strerror(errno));
            close(service_socket_fd);
            exit(1);
        }
        current_max_num++;

        int i=0;
        sprintf(sendbuf,"用户%s上线\n",name);
        while(i < current_max_num)                                        //以此循环将消息发送到所有客户端
        {
            /* if(i == current_max_num-1)
            {
                continue;
            } */
            ssize_t send_ret = send(client[i],sendbuf,sizeof(sendbuf),0);
            if(send_ret == -1)
            {
                fprintf(stderr,"消息发送失败：%s\n",strerror(errno));
                close(service_socket_fd);
                exit(1);
            }
            i++;
            printf("%d\n",i);
        }
        
        if(current_max_num == 1)
        {
            int pthread_ret2 = pthread_create(&check_send_thid,NULL,check_client_send,NULL);
            if(pthread_ret2 == -1)
            {
                fprintf(stderr,"创建线程check_client_send失败：%s\n",strerror(errno));
                close(service_socket_fd);
                exit(1);
            }

            fd = fopen("service_msg","a+");
            if(fd == NULL)
            {
                fprintf(stderr,"创建或打开文件失败：%s\n",strerror(errno));
                fclose(fd);
                close(service_socket_fd);
                exit(1);
            }
        }
    }
}


void *check_client_send(void *argc)
{
    static int var;
    int i;
    int select_n=0;
    fd_set allset,rset;
    FD_ZERO(&allset);                   //将指定的文件描述符清零
    while(1)
    {
        if(current_max_num > 0)
        {
            for(var=0;var<current_max_num;var++)
            {
                FD_SET(client[var],&allset);                        //在文件描述符集合中添加新的文件描述符
            }
            rset = allset;
            select_n = select(FD_SETSIZE,&rset,NULL,NULL,NULL);         //阻塞等待客户端套接字描述符准备就绪
            if(select_n == -1)
            {
                fprintf(stderr,"监听套接字集出错：%s\n",strerror(errno));
                exit(1);
            }
            else
            {
                for(var=0,i=0;  var<current_max_num && i<select_n;  var++)
                {
                    if(FD_ISSET(client[var],&rset))
                    {
                        i++;
                        recv_and_send_to_all_client(var);              
                    }
                }
            }
        }
    }
}


void recv_and_send_to_all_client(int argc)
{
    int i=0,var=argc;

    ssize_t recv_ret = recv(client[var],sendbuf,sizeof(sendbuf),0);
    if(recv > 0)
    {

        //某客户端发送quit下线，删除对应客户端套接字client[var]
        if(strcmp(sendbuf,"QUIT")==0 || strcmp(sendbuf,"Quit")==0 || strcmp(sendbuf,"quit")==0)
        {
            for(;var<current_max_num-1;var++)
            {
                client[var] = client[var+1];
            }
            current_max_num--;
        }

        while(i < current_max_num)                                        //以此循环将消息发送到所有客户端
        {
            /* if(i == argc)
            {
                continue;
            } */
            ssize_t send_ret = send(client[i],sendbuf,sizeof(sendbuf),0);
            if(send_ret == -1)
            {
                fprintf(stderr,"消息发送失败：%s\n",strerror(errno));
                fclose(fd);
                close(service_socket_fd);
                exit(1);
            }
            /* ssize_t write_ret = write(*(int *)fd,sendbuf,sizeof(sendbuf));
            if(write_ret == -1)
            {
                fprintf(stderr,"保存聊天信息失败：%s\n",strerror(errno));
                fclose(fd);
                close(service_socket_fd);
                exit(1);
            } */

            fprintf(fd,"%s\n",sendbuf);
            i++;
        }
    }
}

