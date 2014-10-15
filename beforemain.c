/*************************************************************************
	> File Name: beforemain.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年10月15日 星期三 23时20分05秒
 ************************************************************************/

#include<stdio.h>

__attribute((constructor)) void before_main1()
{
    printf("%s\n",__FUNCTION__);
}

__attribute((constructor)) void before_main2()
{
    printf("%s\n",__FUNCTION__);
}

__attribute((destructor)) void after_main()
{
    printf("%s\n",__FUNCTION__);
}

int
main(int argc, char **argv)
{
    printf("%s\n",__FUNCTION__);
    return 0;
}
