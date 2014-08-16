/*************************************************************************
	> File Name: lkprint.c
	> Author: likang
	> Created Time: 2014年08月16日 星期六 22时31分02秒
 ************************************************************************/

#include<stdio.h>
#include"lkprint.h"

int
main(void)
{
	int a = 0;
	int b = 10;
	char *c = "hello,world!";
	lkprint("%d %d %s\n",a,b,c);
	return 0;
}
