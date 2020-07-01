#include <iostream>
using namespace std;
const int N = 30;
int n;
bool G[N][N];              //存图
int cnt[N];                //cnt[i]为>=i的最大团点数
int points[N];             //最大团的点
int visited[N];            //记录点的位置
int ans;                   //最大团的数目
bool dfs(int pos, int num) //num为已取的点数
{
    for (int i = pos + 1; i <= n; i++)
    {
        if (cnt[i] + num <= ans) //剪枝
            return false;

        if (G[pos][i]) //与当前团中元素比较
        {
            int j;
            for (j = 0; j < num; j++)
                if (!G[i][visited[j]])
                    break;
            if (j == num) //若为空，则皆与i相邻，则此时将i加入到最大团中
            {
                visited[num] = i;
                if (dfs(i, num + 1))
                    return true;
            }
        }
    }
    if (num > ans)
    {
        ans = num;
        for (int i = 1; i <= num; i++)
            points[i] = visited[i - 1];
        return true;
    }
    return false;
}
void maxClique()
{
    ans = -1;
    for (int i = n; i >= 1; i--) //枚举所有点
    {
        visited[0] = i;
        dfs(i, 1);
        cnt[i] = ans;
    }
}
void input()
{
    int t;
    cin >> n >> t;
    for (int i = 0; i < t; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    for (int i = 0; i < n; i++) //把链接了的点取反
    {
        for (int j = 0; j < n; j++)
        {
            if (n != j)
            {
                G[i][j] = 1 - G[i][j];
            }
        }
    }
}
int main()
{
    input();
    maxClique();
    printf("%d\n", ans);
    return 0;
}