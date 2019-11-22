#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    char str[]={"zhao hanqing"};
    char *strp;
    strp = strchr(str,'a');
    printf("%s\n",strp);
    return 0;
}