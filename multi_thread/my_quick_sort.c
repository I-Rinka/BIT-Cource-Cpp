#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//返回中间的位置
int partition(int *addr, int l, int r)
{
    int tl = l;
    int tr = r;

    //取三点法的中值排到第一个
    int a1 = addr[l];
    int mid = (l + r) / 2;
    int a2 = addr[mid];
    int a3 = addr[(r)];

    //找出a1不是中值的各种情况
    if (a1 > a2 && a1 > a3)
    {
        if (a2 > a3)
        {
            //a2是中值
            addr[l] = a2;
            addr[mid] = a1;
        }
        else
        { //a3是中值
            addr[l] = a3;
            addr[r] = a1;
        }
    }
    else if (a1 < a2 && a1 < a3)
    {
        if (a2 < a3)
        {
            //a2是中值
            addr[l] = a2;
            addr[mid] = a1;
        }
        else
        { //a3是中值
            addr[l] = a3;
            addr[r] = a1;
        }
    }

    while (1)
    {
        //左固定，找右边
        while (tl < tr)
        {
            if (addr[tl] > addr[tr])
            {
                int t = addr[tl];
                addr[tl] = addr[tr];
                addr[tr] = t;
                tl++;
                break;
            }
            tr--;
        }
        //右固定，找左边
        while (tl < tr)
        {
            if (addr[tl] > addr[tr])
            {
                int t = addr[tl];
                addr[tl] = addr[tr];
                addr[tr] = t;
                tr--;
                break;
            }
            tl++;
        }

        if (tl >= tr)
        {
            return tr;
        }
    }
}

//小于cutoff就插入排序
void insert_sort(int *addr, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min = addr[i];
        int p = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (min > addr[j])
            {
                min = addr[j];
                p = j;
            }
        }
        if (min != addr[i])
        {
            addr[p] = addr[i];
            addr[i] = min;
        }
    }
}

void my_qsort(int *addr, int l, int r)
{
    int cutoff = 15;
    if (r - l + 1 < cutoff)
    {
        insert_sort(addr, l, r);
    }
    else
    {
        int pivote = partition(addr, l, r);
        if (l < pivote)
        {
            my_qsort(addr, l, pivote);
        }
        if (r > pivote + 1)
        {
            my_qsort(addr, pivote + 1, r);
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    // int n = rand() % 100;
    int n = 10000;
    int *addr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        addr[i] = rand() % 1000;
        // scanf("%d",&addr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", addr[i]);
    }

    printf("\n-------------\n");
    // int pivote = partition(addr, 0, n - 1);
    my_qsort(addr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", addr[i]);
    }
    // printf("\n%d", addr[pivote]);
    return 0;
}
