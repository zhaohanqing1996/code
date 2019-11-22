#include<unistd.h>
#include<ctype.h>
#include<sys/signal.h>
#include<sys/param.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    __uid_t uid;
    uid = getuid();
    printf("%d\n",uid);
    return 0;
}