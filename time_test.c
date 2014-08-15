/*************************************************************************
	> File Name: time_test.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年08月12日 星期二 14时28分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void
clock_test()
{
	clock_t t1 = clock();
	int i,sum =0;
	for(i = 0; i < 100000; i++)
		sum += i;
	printf("sum of 1 to 1000 is %d\n",sum);
	clock_t t2 = clock();
	long ti = (t2-t1)*1000000/CLOCKS_PER_SEC;
	printf("CLOCKS_PER_SEC is %ld\n",CLOCKS_PER_SEC);
	printf("the program takes %ld us\n",ti);
}
void
time_ex()
{
	time_t t1 = time(NULL);
	char *bu = ctime(&t1);
	struct tm *t = localtime(&t1); 
	
	printf("%s\n",bu);
	printf("%d 年 %d 月 %d 日 %d 时 %d 分 %d 秒\n",t->tm_year + 1900,t->tm_mon + 1,\
			t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}
int
main(void)
{
	time_ex();
	return 0;
}
	
