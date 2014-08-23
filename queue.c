/*************************************************************************
	> File Name: queue.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月23日 星期六 21时58分15秒
 ************************************************************************/

#include<stdio.h>
#include"queue.h"
#include<malloc.h>
#include<assert.h>

typedef struct QUEUE
{
    int value;
    struct QUEUE *next;
}QueueNode;

static QueueNode *front;
static QueueNode *rear;

void
insert(int value)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    assert(node != NULL);
    node->value = value;
    node->next = NULL;
    if (front == NULL)
    {
        front = node;
    }
    else
    {
        rear->next = node;
    }
    rear = node;
}

void
delete(void)
{
    QueueNode *node;
    assert(!is_empty());
    node = front;
    front = node->next;
    if (front == NULL)
        rear = NULL;
    free(node);
}

int
first(void)
{
    assert(!is_empty());
    return front->value;
}

int
is_empty(void)
{
    return (front == NULL);
}

int
is_full(void)
{
    return 0;
}

void
destroy_queue(void)
{
    while(!is_empty())
    {
        delete();
    }
}

int
main(void)
{
    int i;
    int value;
    for ( i = 0; i < 5; i++ )
    {
        scanf("%d",&value);
        getchar();
        insert(value);
    }

    printf("queue front is :%d\n",first());
    delete();
    printf("queue front is :%d\n",first());
    destroy_queue();
    printf("queue front is :%d\n",first());
    return 0;
}
