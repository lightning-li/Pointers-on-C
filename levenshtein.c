/*************************************************************************
	> File Name: levenshtein.c
	> Author: 
	> Mail: 
	> Created Time: 2014年08月19日 星期二 10时22分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int leven(char *a, char *b);
int
leven(char *a, char *b)
{
    int alen = strlen(a);
    int blen = strlen(b);
    int len = blen;
    int *v0, *v1,*tmp;
    int i,j,cost,small;
    v0 = (int *) malloc((len + 1) * sizeof(int));
    v1 = (int *) malloc((len + 1) * sizeof(int));
    for ( i = 0; i <= len ; i++)
    {
        *(v0 + i) = i;
    }
    for ( i = 1; i <= alen; i++ )
    {
        v1[0] = i;
        for ( j = 1; j <= blen; j++ )
        {
            if ( a[i - 1] == b[j - 1] )
                cost = 0;
            else
                cost = 1;
            small = (v1[j-1] + 1) < (v0[j] +1) ? (v1[j-1] + 1) : (v0[j] + 1);
            small = small < (v0[j-1] + cost) ? small : (v0[j-1] + cost);

            v1[j] = small;
        }
        tmp = v0;
        v0 = v1;
        v1 = tmp;

    }
    for ( i = 0; i <= blen; i++)
        printf("%d  ",v0[i]);
    return v0[blen];
}
int
main(void)
{
    char *a,*b;
    a = (char *)malloc(100*sizeof(char));
    b = (char *)malloc(100*sizeof(char));
    int num;
    for (num = 0; num < 5; num++)
    {
        fscanf(stdin,"%s",a);
        fscanf(stdin,"%s",b);
        int i = leven(a,b);
        printf("from %s to %s at least change %d times\n",a,b,i);
    }
    return 0;
}
