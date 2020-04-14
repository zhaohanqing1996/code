#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

void process_info(int fd)
{
    int send_num;
    char send_buf [] = "helloworld";
    char recv_buf [4096];
    char str1[4096];
    while (1)
    {
        printf("begin send\n");
        memset(str1,0,4096);
        strcat(str1, "POST http://api.day.app/seFqfLJGHTWDvXnGZPYeRP/今天带饭了吗？ HTTP/1.1\r\n");
        strcat(str1,"Host: api.day.app\r\n");
        strcat(str1,"Content-Length: 0\r\n");
        strcat(str1,"\r\n\r\n");
        printf("str1 = %s\n",str1);
        send_num = send(fd, str1,strlen(str1),0);
        if (send_num < 0)
        {
            perror("send error");
            return;
        }
        else
        {

        printf("send successful\n");
        printf("begin recv:\n");
        int recv_num = recv(fd,recv_buf,sizeof(recv_buf),0);
        if(recv_num < 0){
            perror("recv");
            return;
        } else {
                printf("recv sucess:%s\n",recv_buf);
                }
         }
        break;
        sleep(5);
    }
}

void main(void)
{
        int sock_fd;
        struct sockaddr_in addr_serv;
        struct hostent* hostInfo;

    printf("...\n");
        sock_fd=socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd < 0)
    {
        perror("sock error");
        return;
    }
        else
    {
        printf("sock successful");
    }

        hostInfo = gethostbyname("api.day.app");
        if(NULL == hostInfo)
        {
        printf("hostInfo is null\n");
        return;
    }

        memset(&addr_serv, 0, sizeof(addr_serv));
        addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(80);

        printf("Ip address = %s \n",inet_ntoa(*((struct in_addr*)hostInfo->h_addr)));
        memcpy(&addr_serv.sin_addr, &(*hostInfo->h_addr_list[0]), hostInfo->h_length);

        if (connect(sock_fd, (struct sockaddr*)(&addr_serv), sizeof(addr_serv)) < 0)
    {
        perror("connect error\n");
        return;
    }
    else
    {
        printf("connect successful\n");
    }
        process_info(sock_fd);
}