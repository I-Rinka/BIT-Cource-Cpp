#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int a[MAX];    //原始数据
int aLen[MAX]; //存以第i个数为终点的序列长度

int Dynamic(int *a, int *aLen, int l)
{
    int n, m;
    int maxLen = 1;

    for (n = 0; n < l; ++n)
        aLen[n] = 1;

    for (n = 1; n < l; ++n)
    {
        aLen[n] = 1; //最小为一

        for (m = 0; m < n; ++m) //寻找以a[n]结尾的最长序列(末尾比a[n]小且长度最长的序列)
            if (a[n] > a[m] && aLen[m] + 1 > aLen[n])
                aLen[n] = aLen[m] + 1;

        if (aLen[n] > maxLen) //标记当前的最长序列
            maxLen = aLen[n];
    }

    return maxLen;
}
int len;
void init(int *IntSequence)
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            scanf("%d", &IntSequence[i]);
            break;
        }
        scanf("%d,", &IntSequence[i]);
    }
}
int main()
{
    freopen("C:/Users/I_Rin/Desktop/py/random.txt", "r", stdin);
    freopen("C:/Users/I_Rin/Desktop/py/output.txt", "w", stdout);
    for (int i = 0; i < 100; i++)
    {
        init(a);
        cout << Dynamic(a, aLen, len)<<endl;
    }
}
/*
void init(vector<int> &arr)
{
    scanf("%d", &len);
    int *IntSequence = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            scanf("%d", &IntSequence[i]);
            break;
        }
        scanf("%d,", &IntSequence[i]);
        arr.push_back(IntSequence[i]);
    }
}*/
