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
#include <sys/select.h>
#include <poll.h>

#define PORT 8888
#define IP "127.0.0.1"

struct client_name{
    char name[16][16];
    int num;
};
//void *pthread_service(void);

int main(int argc,char *argv[])
{
    struct sockaddr_in sockaddr_in1;
    struct sockaddr_in sockaddr_in2;
    int socket_fd,socket_fd2;
    char buf[256] = {0},str[256] = {0};
    struct client_name client={0};
    fd_set fd_set1,readfds;
    int nfds=0,fd_num_max=0;
    //pthread_t pthread1;

    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        printf("socket creat failed\n");
        return -1;
    }
    printf("socket creat successfully\n");

    memset(&sockaddr_in1,0,sizeof(sockaddr_in1));
    sockaddr_in1.sin_addr.s_addr = inet_addr(IP);
    sockaddr_in1.sin_family = AF_INET;
    sockaddr_in1.sin_port = htons(PORT);

    int bind_ret = bind(socket_fd,(struct sockaddr *)&sockaddr_in1,sizeof(sockaddr_in1));
    if(bind_ret == -1)
    {
        printf("bind error\n");
        return -1;
    }
    printf("bind successfuly\n");

    int listen_ret = listen(socket_fd,10);
    if(listen_ret == -1)
    {
        printf("listen failed\n");
        return -1;
    }
    printf("listen successfuly\n");

    FD_ZERO(&fd_set1);
    FD_SET(socket_fd,&fd_set1);
    fd_num_max = nfds;
    nfds = socket_fd + 1;

    while(1)
    {
        int var_socket_fd=0;
        readfds = fd_set1;
        int select_ret = select(nfds,&readfds,NULL,NULL,NULL);
        if(select_ret == -1)
        {
            printf("select error\n");
            return -1;
        }
        //printf("select successfuly\n");

        for(var_socket_fd=0;var_socket_fd<nfds;var_socket_fd++)
        {
            if(FD_ISSET(var_socket_fd,&readfds))            //the variable value in readfds
            {
                if(var_socket_fd == socket_fd)              //the variable value is service_socket_fd
                {
                    socklen_t sockaddr_in2_len = sizeof(sockaddr_in2);
                    socket_fd2 = accept(socket_fd,(struct sockaddr *)&sockaddr_in2,&sockaddr_in2_len);
                    if(socket_fd2 == -1)
                    {
                        printf("accept error\n");
                        return -1;
                    }
                    printf("client %d connect successfuly\n",socket_fd2);
                    client.num = var_socket_fd;
                    recv(socket_fd2,client.name[client.num],sizeof(client.name[client.num]),0);
                    sprintf(buf,"Welcome %s to HexChat\n",client.name[client.num]);
                    send(socket_fd2,buf,sizeof(buf),0);
                    FD_SET(socket_fd2,&fd_set1);
                    fd_num_max = fd_num_max > socket_fd2 ? fd_num_max:socket_fd2;
                    nfds = fd_num_max + 1;
                }
                else                            //the var is client_socket_fd
                {
                    //pthread_create(&pthread1,NULL,pthread_service,NULL);

                    bzero(buf,sizeof(buf));
                    int read_ret = read(var_socket_fd,buf,sizeof(buf));
                    if(read_ret < 0)
                    {
                        perror("read client_socket_fd");
                        FD_CLR(var_socket_fd,&fd_set1);
                        close(var_socket_fd);
                    }
                    else if(read_ret == 0)
                    {
                        printf("client %d disconnect\n",var_socket_fd);
                        FD_CLR(var_socket_fd,&fd_set1);
                        close(var_socket_fd);
                    }
                    else
                    {
                        //printf("client %d:%s\n",var_socket_fd,buf);
                        sprintf(str,"%s:%s\n",client.name[client.num],buf);
                        send(var_socket_fd,str,sizeof(str),0);
                    }
                }
            }
        }
    }
    close(socket_fd2);
    close(socket_fd);
    return 0;
}

/* void *pthread_service(void)
{

} */