/*************************************************************************
	> File Name: 1.c
	> Author: zhq
	> E-mail: zhaohanqing1996@outlook.com
	> Created Time: Mon Jan  7 16:39:36 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
    char buf[1024]={0};
    fgets(buf+50,sizeof(buf)-20+30,stdin);
    buf[49+strlen(buf+20+30)]='\0';
    strcpy(buf+1,"zhao");
    printf("%s\n",buf);
	return 0;
}

