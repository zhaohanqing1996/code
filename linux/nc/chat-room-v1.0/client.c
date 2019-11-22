#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define PORT 8888
#define IP "127.0.0.1"

void *pthread_func(void);
int socket_fd;
char buf[256]={0};
char name[10][16]={0};
struct sockaddr_in sockaddr_in1;
int main(int argc,char *argv[])
{
    pthread_t pthread_id_1;
    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        printf("socket creat failed\n");
        return -1;
    }
    printf("socket creat successfully\n");

    sockaddr_in1.sin_family = AF_INET;
    sockaddr_in1.sin_port = htons(PORT);
    sockaddr_in1.sin_addr.s_addr = inet_addr(IP);

    int connect_ret = connect(socket_fd,(struct sockaddr *)&sockaddr_in1,sizeof(sockaddr_in1));
    if(connect_ret == -1)
    {
        printf("connect service failed\n");
        return -1;
    }
    printf("connect service successfully\n");
    printf("Please input your name\n");
    printf(">");
    scanf("%s\n",buf);
    send(socket_fd,buf,sizeof(buf),0);

    while(1)
    {
        pthread_create(pthread_id_1,NULL,pthread_func,NULL);
        scanf("%s",buf);
        send(socket_fd,buf,sizeof(buf),0);
    }

    close(socket_fd);
    return 0;
}

void *pthread_func(void)
{
    recv(socket_fd,buf,sizeof(buf),0);
    printf("%s\n",buf);
}