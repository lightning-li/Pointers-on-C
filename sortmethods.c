/*************************************************************************
	> File Name: sortmethods.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月21日 星期四 09时36分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void quicksort(int *a, int low, int high);
void heapsort(int *a, int length);
void heapadjust(int *a, int s, int m);

void
heapadjust(int *a, int s, int m)
{
    int i;
    int n = a[s];
    for (i = 2*s; i <= m; i++)
    {
        if (i < m && (a[i] < a[i + 1]))
            i++;
        if (n >= a[i])
            break;
        a[s] = a[i];
        s = i;
    }
    a[s] = n;
}
void heapsort(int *a, int length)
{
    int i;
    int mid = length/2;
    int temp;
    for (i = mid; i > 0; i--)
        heapadjust(a,mid,length);
    for (i = length; i > 0; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapadjust(a,1,i-1);
    }
}
void
quicksort(int *a, int low, int high)
{
    if (low >= high)
        return;
    else
    {
        int i = low;
        int j = high;
        int num = a[low];
        while(i < j)
        {
            while(a[j] >= num && i < j)
                j--;
            a[i] = a[j];
            while(a[i] <= num && i < j)
                i++;
            a[j] = a[i];
        }
        a[i] = num;
        quicksort(a,low,i-1);
        quicksort(a,i+1,high);
        return;

    }
}

int
main(void)
{
    int a[] = {4,8,9,10,1,3,5,6,2,1};
    heapsort(a,10);
    int i;
    for (i = 0; i < 10; i++)
        printf("%d ",a[i]);
    return 0;
}
