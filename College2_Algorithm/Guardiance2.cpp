#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 500 + 10;
const int N = 100 + 10;
int vis[maxn], match[maxn];
int map[maxn][maxn];
int n, maxmatch;
struct node
{
    int h;
    char sex;
    char music[N];
    char sport[N];
} student[maxn];

int dfs(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && map[x][i]) //有空位
        {
            vis[i] = 1;
            if (!match[i] || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

void Hungary()
{
    maxmatch = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis)); //每一轮都制空visited表
        maxmatch += dfs(i);          //每次能搞出空的才
    }
}

int main()
{
    int T;
    while (scanf("%d", &T) != EOF)
    {
        while (T--)
        {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
                cin >> student[i].h >> student[i].sex >> student[i].music >> student[i].sport;
            memset(map, 0, sizeof(map));
            memset(match, 0, sizeof(match));
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (!(abs(student[i].h - student[j].h) > 40 || student[i].sex == student[j].sex || strcmp(student[i].music, student[j].music) || !strcmp(student[i].sport, student[j].sport)))
                        map[i][j] = map[j][i] = 1;
                }
            }
            Hungary();
            printf("%d\n", n - (maxmatch >> 1));
        }
    }
    return 0;
}