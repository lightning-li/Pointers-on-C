/*************************************************************************
	> File Name: str_reverse.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月19日 星期二 16时12分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *str);
void
reverse(char *str)
{
    char ch = ' ';
    char *aa;
    aa = strrchr(str,ch);
    while( aa != NULL )
    {
        printf("%s ",aa+1);
        *aa = '\0';
        aa = strrchr(str,ch);
    }
   // printf("%s",str);
}

void
reverse_seq(char *str,int low,int  len)
{
    int mid = (low + len)/2;
    int i;
    char temp;
    for (i = low; i < mid; i++)
    {
        temp = str[--len];
        str[len] = str[i];
        str[i] = temp;
    }
   // printf("%s",str);
}
int
main(void)
{
    char str[] = "i love your";
    int len = 0;
    while(str[len] != '\0')
        len++;
    reverse_seq(str,0,len);
    printf("%s\n",str);
    int num = 0;
    int low;
    while(num < len)
    {
        low = num;
        while(str[num] != ' ' && num < len)
            num++;
        printf("len = %d\n",num);
        reverse_seq(str,low,num);
        num++;
    }
    printf("%s\n",str);
    return 0;
}
