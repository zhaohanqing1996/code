/*************************************************************************
	> File Name: point.c
	> Author: zhq
	> E-mail: zhaohanqing1996@outlook.com
	> Created Time: Sat Oct 26 10:36:44 2019
 ************************************************************************/

#include <stdio.h>
int main(int argc,char *argv[])
{
	int *a = NULL;
	int b = 1;
	&b = a;
	printf("a = %d\nb = %d\n",*a,b);
	return 0;
}

