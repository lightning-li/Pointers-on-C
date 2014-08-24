#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nqueens(int k, int n);
int locate(int k, int i);
void out(int n);
static int num = 0;
int q[10];
void
nqueens(int k,int n)
{
    if(k > n){

        out(n);
    }
    else
    {
        int i;
        for ( i = 0; i < n; i++)
        {
            if(locate(k,i))
            {
                q[k-1] = i;
                nqueens(k+1,n);
            }
        }

    }
}

int
locate(int k, int i)
{
    int j = 1;
    while(j < k)
    {
        if(abs(i - q[j-1]) == abs(k-j) || i == q[j-1])
            return 0;
        j++;
    }
    return 1;
}
void
out(int n)
{   num++;
    printf("the num %d methods:",num);
    int i;
    for( i = 0; i < n; i++)
        printf("%d  ",q[i]);
    printf("\n");
}
int
main(void)
{
    int n;
    printf("please input the number of queens:");
    scanf("%d",&n);
    nqueens(1,n);
    return 0;
}

