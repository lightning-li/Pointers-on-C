/*************************************************************************
	> File Name: semaphore.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月22日 星期五 14时17分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int size = 0;
sem_t sem;

void provide_data(void);
void handle_data(void);

void
provide_data(void)
{
    int i;
    for (i = 0; i < MAXSIZE; i++)
    {
        sleep(2);
        stack[i] = i;
        printf("%d provider...\n",i);
        sem_post(&sem);
    }
}

void
handle_data(void)
{
    int i;
    while ((i = size++) < MAXSIZE)
    {
        sem_wait(&sem);
        printf("乘法：%d X %d = %d\n",stack[i],stack[i],stack[i]*stack[i]);
        printf("%d handler...\n",i);
        sleep(1);
    }
}

int
main(void)
{
    sem_init(&sem, 0, 0);
    pthread_t provider,handler;
    pthread_create(&provider,NULL,(void *)provide_data,NULL);
    pthread_create(&handler,NULL,(void *)handle_data,NULL);
    pthread_join(provider,NULL);
    pthread_join(handler,NULL);
    sem_destroy(&sem);

    return 0;
}
