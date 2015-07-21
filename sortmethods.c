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
void mergesort(int *a, int *b, int low, int high);
void mergearray(int *a, int m, int mid, int n, int *b);

void mergesort(int *a, int *b,int low, int high)
{

    if (low >= high)
        return;
    int mid = (low + high)/2;
    mergesort(a, b, low, mid);   //左边数组有序
    mergesort(a, b, mid+1, high);//右边数组有序
    mergearray(a,low,mid,high,b);//将两个有序的数组合并成一个有序的数组
}

void mergearray(int *a, int m, int mid, int n, int *b)
{
    int i,j,temp;
    j = mid+1;
    int k = 0;
    temp = m;
    while(m <= mid && j <= n)
    {
        if (b[m] < b[j])
        {
            a[k++] = b[m];
            m++;
        }
        else
        {
            a[k++] = b[j];
            j++;
        }
    }
    while (m <= mid)
        a[k++] = b[m++];
    while (j <= n)
        a[k++] = b[j++];
    for (i = 0; i < k; i++)
        b[i+temp] = a[i];
}

void
heapadjust(int *a, int s, int m)
{
    int i;
    int n = a[s];
    
	while (2*s <= m)
    {
		i = 2*s;
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
    {
        heapadjust(a,i,length);
    }
    for (i = length; i > 1; i--)
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
    int a[] = {10,8,9,10,1,3,5,6,2,1,15};
    heapsort(a,10);
    int i;
    for (i = 1; i <= a[0]; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    int b[] = {8,3,1,5,9,13};
    quicksort(b,0,5);
    for (i = 0; i < 6; i++)
        printf("%d ",b[i]);
    printf("\n");

    int c[] = {8,3,1,5,9,13};
    int d[6];
    mergesort(d,c,0,5);
    for (i = 0; i < 6; i++)
        printf("%d ",c[i]);
    printf("\n");
    return 0;
}
