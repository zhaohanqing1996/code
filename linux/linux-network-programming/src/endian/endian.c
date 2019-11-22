#include<stdio.h>

int main()
{
    int value = 1;
    if(((char *)&value)[0])
    {
        printf("小端字节序\n");
    }
    else
    {
        printf("大端字节序\n");
    }
    return value;
}
