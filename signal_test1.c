/*************************************************************************
	> File Name: signal_test.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月26日 星期二 17时21分57秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

void
catch_ctlc(int sig_num)
{
    printf("\nCatch Ctrl+c\n");
    fflush(stdout);
    return;
}

int
main(void)
{
    signal(SIGINT,catch_ctlc);
    printf("Go ahead , make your day !\n");
    pause();
    return 0;
}
