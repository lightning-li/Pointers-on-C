/*************************************************************************
	> File Name: pthread_key_test.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月26日 星期二 15时58分39秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>

static pthread_key_t log_key;

void
write_to_thread_log (const char *message)
{
    FILE *thread_log = (FILE *) pthread_getspecific(log_key);
    fprintf(thread_log,"%s\n",message);
}

void
close_log_file(void *thread_log)
{
    fclose((FILE *)thread_log);
}

void
thread_function(void *args)
{
    char log_filename[20];
    FILE *thread_log;
    sprintf(log_filename,"thread%d.log",(int) pthread_self());
    thread_log = fopen(log_filename,"w");
    pthread_setspecific(log_key,thread_log);
    write_to_thread_log("Thread starting.");
}

int
main(void)
{
    int i;
    pthread_t threads[5];
    pthread_key_create(&log_key,close_log_file);

    for (i = 0; i < 5; i++)
    {
        pthread_create(&threads[i],NULL,(void *)thread_function,NULL);

    }

    for (i = 0; i < 5; i++)
    {
        pthread_join(threads[i],NULL);
    }
    return 0;
}
