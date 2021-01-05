#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define cutoff 10
#define th_cutoff 100
//�����м��λ��
int partition(int *addr, int l, int r)
{
    int tl = l;
    int tr = r;

    //ȡ���㷨����ֵ�ŵ���һ��
    int a1 = addr[l];
    int mid = (l + r) / 2;
    int a2 = addr[mid];
    int a3 = addr[(r)];

    //�ҳ�a1������ֵ�ĸ������
    if (a1 > a2 && a1 > a3)
    {
        if (a2 > a3)
        {
            //a2����ֵ
            addr[l] = a2;
            addr[mid] = a1;
        }
        else
        { //a3����ֵ
            addr[l] = a3;
            addr[r] = a1;
        }
    }
    else if (a1 < a2 && a1 < a3)
    {
        if (a2 < a3)
        {
            //a2����ֵ
            addr[l] = a2;
            addr[mid] = a1;
        }
        else
        { //a3����ֵ
            addr[l] = a3;
            addr[r] = a1;
        }
    }

    while (1)
    {
        //��̶������ұ�
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
        //�ҹ̶��������
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

//С��cutoff�Ͳ�������
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
typedef struct param
{
    int *addr;
    int l;
    int r;
} PARAM;
void my_qsort(int *addr, int l, int r);
DWORD WINAPI ThreadFunc(LPVOID lpParam)
{
    PARAM param = *((PARAM *)lpParam);
    my_qsort(param.addr, param.l, param.r);
    HeapFree(GetProcessHeap(), 0, lpParam);
    return 0;
}
void my_qsort(int *addr, int l, int r)
{
    if (r - l + 1 < cutoff)
    {
        insert_sort(addr, l, r);
    }
    else if (r - l + 1 >= th_cutoff)
    {
        PARAM *para = (PARAM *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(PARAM));
        para->addr = addr;
        para->l = l;
        para->r = r;
        CreateThread(NULL, 0, ThreadFunc, para, 0, NULL);
    }
    else
    {
        int pivote = partition(addr, l, r);
        my_qsort(addr, l, pivote);
        my_qsort(addr, pivote + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    // srand(clock());
    // int n = rand() % 100;
    int n = 10;
    scanf("%d", &n);
    int *addr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", addr + i);
        // addr[i] = rand() % 1000;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", addr[i]);
    // }
    printf("\n");
    my_qsort(addr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", addr[i]);
    }
    return 0;
}
