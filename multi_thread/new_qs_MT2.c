#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define MUTEX_NAME "MT_MUTEX"

int cutoff = 3;
int th_max = 100;
int th_now = 0;
HANDLE hThreads[100];

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
typedef struct param
{
    int *addr;
    int len;
} PARAM;
void my_qsort(int *s, int length);
DWORD WINAPI ThreadFunc(LPVOID lpParam)
{
    PARAM param = *((PARAM *)lpParam);
    my_qsort(param.addr, param.len);
    return 0;
}
void my_qsort(int *s, int length)
{
    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, MUTEX_NAME);
    WaitForSingleObject(hMutex,INFINITE);
    if (length < 3)
    {
        ReleaseMutex(hMutex);
        if (length == 2 && s[0] > s[1])
        {
            int t = s[1];
            s[1] = s[0];
            s[0] = t;
        }
    }
    else if (length > 1000 && th_now < th_max - 1)
    {
        PARAM *para = (PARAM *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(PARAM));
        int middle = partition(s, length);
        para->addr = s;
        para->len = middle;
        hThreads[th_now] = CreateThread(NULL, 0, ThreadFunc, para, 0, NULL);
        th_now++;

        para->addr = s + middle + 1;
        para->len = length - middle - 1;
        hThreads[th_now] = CreateThread(NULL, 0, ThreadFunc, para, 0, NULL);
        th_now++;
        HeapFree(GetProcessHeap(), 0, para);
        ReleaseMutex(hMutex);
    }
    else
    {
        ReleaseMutex(hMutex);
        int middle = partition(s, length);
        my_qsort(s, middle);
        my_qsort(s + middle + 1, length - middle - 1);
    }
    CloseHandle(hMutex);
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
        s[i] = rand() % 10000;
    }
    //	int p=partition(s,n);

    CreateMutex(NULL, FALSE, MUTEX_NAME);

    time_t start = GetTickCount64();
    my_qsort(s, n);
    WaitForMultipleObjects(th_now, hThreads, TRUE, INFINITE);
    time_t last_time = GetTickCount64() - start;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }

    printf("\n %lld", last_time);
    //	printf("\n%d\n",p);
}