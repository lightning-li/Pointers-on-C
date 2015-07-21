/*************************************************************************
	> File Name: changeable_args.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年08月12日 星期二 19时00分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

float
average(int num,...)
{
	va_list var_arg;
	int count;
	float sum = 0;
	va_start(var_arg,num);
	for(count = 0; count < num; count++)
	{
		sum += va_arg(var_arg, int);
	}
	va_end(var_arg);
	//vprintf("%d %d %d %d",var_arg);
	return sum / num;
}
int
main(void)
{
	float av = average(5,1,2,3,4,5);
	if( system(NULL) != 0)
		printf("存在命令解释器\n");
	printf("%f\n",av);
	return 0;
}

