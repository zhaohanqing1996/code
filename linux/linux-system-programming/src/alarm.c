#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle()
{
    printf("alarm!\a\n");
}

int main()
{
    signal(SIGALRM,handle);
    alarm(5);
    for(int i = 0;i < 7;i++)
    {
        printf("sleep %d\n",i);
        sleep(1);
    }
    //sleep(6);
    return 0;
}
