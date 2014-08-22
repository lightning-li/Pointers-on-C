/*************************************************************************
	> File Name: pthread_test.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月21日 星期四 17时39分20秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void print_message(const void *ptr);

int
main(void)
{
    int tmp1, tmp2;
    void *retval;
    pthread_t thread1, thread2;
    char *ms1 = "thread 1";
    char *ms2 = "thread 2";
    int ret_thrd1, ret_thrd2;
    ret_thrd1 = pthread_create(&thread1,NULL,print_message,ms1);
    ret_thrd2 = pthread_create(&thread2,NULL,print_message,ms2);
    if (ret_thrd1 != 0)
        printf("thread1 create failed\n");
    else
        printf("thread1 create successfully\n");
    if (ret_thrd2 != 0)
        printf("thread2 created failed\n");
    else
        printf("thread2 created succssfully\n");
    tmp1 = pthread_join(thread1,&retval);
    printf("thread1 return value(retval) is %d\n",(int)retval);
    printf("thread1 return value(tmp) is %d\n",tmp1);
    if (tmp1 != 0)
        printf("can not join with thread1\n");
    printf("thread1 end\n");
    tmp2 = pthread_join(thread2,&retval);
    printf("thread2 return value(retval) is %d\n",(int)retval);
    printf("thread2 return value(tmp) is %d\n",tmp2);
    if (tmp2 != 0)
        printf("can not join with thread2\n");
    printf("thread2 end\n");
}

void
print_message(const void *ptr)
{
    int i = 0;
    for (i; i < 5; i++)
    printf("%s:%d\n",(char *)ptr,i);
}
