#include <iostream>
using namespace std;
int DIM_LEN = 0;
int G[1000][1000];
int visited[1000];
int visited2[1000];
int dfs(int now_dim, int pre_dim)
{
    visited[now_dim] = 1;
    int judge = 0;
    for (int i = 0; i < DIM_LEN; i++)
    {
        if (i != pre_dim)
        {
            if (G[now_dim][i])
            {
                if (visited[i])
                {
                    visited[now_dim] = 0;
                    return 1;
                }
                judge = dfs(i, now_dim);
            }
        }
    }
    visited[now_dim] = 0;
    return judge;
}
int main(int argc, char const *argv[])
{
    cin >> DIM_LEN;
    for (int i = 0; i < DIM_LEN; i++)
    {
        for (int j = 0; j < DIM_LEN; j++)
        {
            cin >> G[i][j];
        }
    }
    int judge = 0;
    for (int i = 0; i < DIM_LEN; i++)
    {
        for (int j = 0; j < DIM_LEN; j++)
        {
            judge += dfs(i, 100000);
        }
    }
    if (judge)
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }
    return 0;
}
