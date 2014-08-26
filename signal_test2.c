/*************************************************************************
	> File Name: signal_test2.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月26日 星期二 19时55分46秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

void
usr1_handler(int sig_num)
{
    printf("Parent (%d) got the SIGUSR1\n",getpid());
}

int
main(void)
{
    pid_t ret;
    int status;
    int role = -1;
    ret = fork();
    if (ret > 0)
    {
        printf("Parent:this is the Parent process(pid %d)\n",getpid());
        signal(SIGUSR1,usr1_handler);
        role = 0;
        pause();
        printf("Parent waiting for chile exit!\n");
        ret = wait(&status);
    }
    else if (ret == 0)
    {
        printf("Child: this is the Child process(pid %d)\n",getpid());
        role = 1;
        sleep(1);
        printf("Child:Sending SIGUSR1 to pid %d\n",getppid());
        kill(getppid(),SIGUSR1);
        sleep(2);
    }
    else
    {
        printf("Error fork process!\n");
    }
    char *mess = (role == 0) ? "Parent" : "Child";
    printf("%s exiting\n",mess);
    return 0;
}
