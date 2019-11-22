#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if(!pid)
    {
        perror("I am child progess!\n");
        sleep(10);
        return 0;
    }
    else
    {
        printf("send signal to child process %d\n",pid);
        sleep(1);
        kill(pid,SIGABRT);
        wait(&status);
        if(WIFSIGNALED(status))
        {
            printf("child process receive signal %d\n",WIFSIGNALED(status));
        }

    }
}