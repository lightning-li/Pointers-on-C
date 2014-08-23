/*************************************************************************
	> File Name: setjmp_test.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月23日 星期六 19时27分33秒
 ************************************************************************/

#include<stdio.h>
#include<setjmp.h>

static jmp_buf buf;

void
second(void)
{
    printf("Second!\n");
    longjmp(buf,1);

}

void
first(void)
{
    second();
    printf("first!\n");
}

int
main(void)
{
    switch(setjmp(buf))
    {
        case 0:
            first();
            break;
        case 1:
            printf("main\n");
            break;
        default:
            break;
    }
    return 0;
}
