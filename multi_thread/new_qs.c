#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cutoff = 3;
int partition(int *s, int length)
{
    int l = 0, r = length - 1;
    int pivote = s[0];
    while (l < r)
    {
        while (s[r] >= pivote && l < r)
        {
            r--;
        }
        s[l] = s[r];
        while (s[l] <= pivote && l < r)
        {
            l++;
        }
        s[r] = s[l];
    }
    s[l] = pivote;
    return l;
}
void bubleSort(int *s, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (s[i] > s[j])
            {
                int t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}
void my_qsort(int *s, int length)
{
    if (length < 3)
    {
        if (length == 2 && s[0] > s[1])
        {
            int t = s[1];
            s[1] = s[0];
            s[0] = t;
        }
        return;
    }
    int middle = partition(s, length);
    my_qsort(s, middle);
    my_qsort(s + middle + 1, length - middle - 1);
}
int main()
{
    //	printf("hello world");
    // scanf("%d", &n);
    srand(time(0));
    int n = 10000;
    int *s = (int *)malloc((sizeof(int) * n));
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", s + i);
        s[i]=rand()%10000;
    }
    //	int p=partition(s,n);
    my_qsort(s, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }
    //	printf("\n%d\n",p);
}