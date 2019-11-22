#include <sys/param.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/time.h>
#include <sys/signal.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <resolv.h>

int main(int argc,char *argv[])
{
    int ch;
    printf("a\n");
    while((ch = getopt(argc,argv,"I:LRc:dfh:i:l:np:qrs:t:v")) != EOF)
    {
        printf("123\n");
    }
    return 0;
}