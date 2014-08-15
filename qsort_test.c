/*************************************************************************
	> File Name: qsort_test.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年08月12日 星期二 19时50分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int
compare(void const *a, void const *b)
{
	char **aa = (char **)a;
	char **bb = (char **)b;
	return strcmp(*aa, *bb);
}
int
compint(void const *a, void const *b)
{
	int *aa = (int *)a;
	int *bb = (int *)b;
	return (*aa - *bb);
}
int
main(void)
{
	int i;
	char *arr[10] = {"ac","ab","ba","bc","ee","ea","dc","df","lk","ss"};
	int ar[5] = {4,1,3,2,5};
	qsort(arr, 10,sizeof(arr[0]),compare);
	for(i = 0; i < 10; i++)
		printf("%s ",arr[i]);
	qsort(ar,5,sizeof(int),compint);
	for(i = 0; i < 5; i++)
		printf("%d ",ar[i]);
	char **t;
	char *key = "bcu";
	t = bsearch(&key,arr,10,sizeof(arr[0]),compare);
	if(t == NULL)
		printf("dont exit\n");
	else
		printf("\n %s\n",*t);
	return 0;
}
