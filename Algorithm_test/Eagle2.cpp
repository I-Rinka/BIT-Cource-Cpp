#include <iostream>
#include <vector>
using namespace std;
struct Eagle
{
    // int num;
    int wing;
    int height;
    int leg;
    vector<int> next; //只把小的塞next里
};
const int maxN = 500 + 2;
Eagle Eagles[maxN];
int remainHeight[maxN];
int n = 0;
int BestH = 0;
int DFS(int x, int nowHeight) //nowHeight有自己的和以前所有的高度
{
    int ans = Eagles[x].height;
    int maxNextHeight = 0;
    int height = 0;
    for (int i = 0; i < Eagles[x].next.size(); i++)
    {
        int nextEalge = Eagles[x].next[i];                                           //这玩意翅膀一定小
        if (nowHeight + Eagles[nextEalge].height + remainHeight[nextEalge] > BestH) //余下所有加上自己加上前人都打不过BestH
        {
            height = DFS(nextEalge, nowHeight + Eagles[nextEalge].height);
        }
        if (nowHeight + height > BestH)
        {
            BestH = nowHeight + height;
        }
        if (height > maxNextHeight)
        {
            maxNextHeight = height;
        }
    }
    //没有后续节点：返回自己的身高
    //有后续节点：返回自己的身高+DFS后最高的身高
    return Eagles[x].height + maxNextHeight;
}
int input()
{
    cin >> n;
    // int tempK[n];
    // vector<vector<int>> tempK;
    vector<int> tempK[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> Eagles[i].wing >> Eagles[i].height >> Eagles[i].leg >> k;
        for (int j = 0; j < k; j++)
        {
            int ki;
            cin >> ki;
            tempK[i].push_back(ki - 1);
        }
    }
    //预处理
    for (int i = 0; i < n; i++) //把所有比这只翅膀短的身高给加上去
    {
        for (int s = 0; s < tempK[i].size(); s++)
        {
            if (Eagles[i].wing > Eagles[tempK[i][s]].wing)
            {
                Eagles[i].next.push_back(tempK[i][s]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (Eagles[j].wing < Eagles[i].wing)
            {
                remainHeight[i] += Eagles[j].height;
            }
        }
    }
    //dfs
    int height = 0;
    int MaxHeight = 0;
    for (int i = 0; i < n; i++)
    {
        height = DFS(i, Eagles[i].leg) + Eagles[i].leg;
        if (height > MaxHeight)
        {
            MaxHeight = height;
            BestH = height;
        }
    }
    cout << MaxHeight << endl;
    BestH = 0;
}
int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        input();
    }
    return 0;
}