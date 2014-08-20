/*************************************************************************
	> File Name: list_test.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月20日 星期三 23时34分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct list
{
    int value;
    struct list *next;
};

void
insert(struct list **linkp, int value)
{
    struct list *current;
    struct list *new;
    while((current = *linkp) != NULL && current->value < value )
    {
        linkp = &current->next;
    }
    new = (struct list *)malloc(sizeof(struct list));
    new->value = value;
    new->next = current;
    *linkp = new;
}
int
main(void)
{
    struct list *head = NULL;
    int i;
    int value;
    for (i = 0; i < 5; i++)
    {
        scanf("%d",&value);
        getchar();
        insert(&head,value);
    }
    struct list *p = head;
    while(p != NULL)
    {
        printf("%d ",p->value);
        p = p->next;
    }
    return 0;
    
}
