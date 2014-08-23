/*************************************************************************
	> File Name: stack.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月23日 星期六 20时45分53秒
 ************************************************************************/

#include<stdio.h>
#include"stack.h"
#include<assert.h>
#include<malloc.h>

typedef struct STACKNODE
{
    int value;
    struct STACKNODE *next;
}StackNode;

static StackNode *stack;

void push(int value)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->value = value;
    node->next = stack;
    stack = node;
}

void
pop(void)
{
    assert(!is_empty());
    StackNode *p = stack;
    stack = p->next;
    free(p);
}

int
is_empty(void)
{
    return (stack == NULL);
}

int
is_full(void)
{
    return 0;
}

void
destory()
{
    while(stack != NULL)
        pop();
}

int
top(void)
{
    assert(!is_empty());
    return stack->value;
}

int
main(void)
{
    int i;
    int value;
    for (i = 0; i < 5; i++)
    {
        scanf("%d",&value);
        getchar();
        push(value);
    }
    printf("stack top element is :%d\n",top());
    pop();
    printf("stack top element is :%d\n",top());
    destory();
    //printf("stack top element is :%d\n",top());
    return 0;
}
