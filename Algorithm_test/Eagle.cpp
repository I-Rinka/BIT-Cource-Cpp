#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Eagle
{
    // int num;
    int wing;
    int height;
    int leg;
    vector<int> want;
};
int n;
Eagle Eagles[501];
int Matrix[501][501];
int visited[501];
int bestH = 0;
int TowardHeight[501];
int DFS(int x, int height) //从大到小叠
{
    int ans = 0;
    int value = 0;
    for (int i = 0; i < Eagles[x].want.size(); i++)
    {
        int otherNUM = Eagles[x].want[i];
        if (Eagles[x].wing > Eagles[otherNUM].wing)
        {
            //限界条件：已有身高加上剩下身高要比最好的高
            if (bestH < height + TowardHeight[otherNUM])
            {
                value = DFS(otherNUM, height + Eagles[x].height);
            }
        }
        if (value > ans)
        {
            ans = value;
        }
    }
    return ans + value;
}
int input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d%d%d%d", &Eagles[i].wing, &Eagles[i].height, &Eagles[i].leg, &k);
        Eagles[i].want.push_back(k);
        Eagles[k].want.push_back(i);
    }
    for (int i = 0; i < n; i++) //把所有比这只翅膀短的身高给加上去
    {
        for (int j = 0; j < n; j++)
        {
            if (Eagles[j].wing < Eagles[i].wing)
            {
                TowardHeight[i] += Eagles[j].height;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        memset(Matrix, 0, sizeof(Matrix));
        input();
    }
    return 0;
}
