#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int **mount;
int **dis;
int **dp;
int number;
struct point
{
    int toNextdis;
    int money;
};
point *P;
int minus(int &i)
{
    i--;
    if (i < 0)
    {
        i = number - 1;
    }
    return i;
}
int plus(int &i)
{
    i++;
    if (i >= number)
    {
        i = 0;
    }
    return i;
}
//点到点货物的数量和点到点之间的距离都需要使用dp算
int mountDp()
{

}
//先解决问题再存数据的技术//备忘录？
int init()
{
    scanf("%d", &number);
    mount = (int **)malloc(sizeof(int *) * number);
    dis = (int **)malloc(sizeof(int *) * number);
    dp = (int **)malloc(sizeof(int *) * number);
    P = (point *)malloc(sizeof(point) * number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d%d", &P[i].money, &P[i].toNextdis);
    }
    for (int i = 0; i < number; i++)
    {
        mount[i] = (int *)malloc(sizeof(int) * number)
        ;
        dis[i] = (int *)malloc(sizeof(int) * number);
        dp[i] = (int *)malloc(sizeof(int) * number);
    }
}
int dpSlove(int l, int r)
{
    if (dp[l][r] != INF)
        return dp[l][r];
    if (l < 0 || r < 0)
        return 0;
    if (l = r)
        return dp[l][r] = 0;
    if (l > r)
    {
        dp[l][r] = min(dpSlove(l - 1, r) + mount[l - 1][r] * dis[l][l - 1], dpSlove(r, l - 1) + mount[l - 1][r] * dis[l][r]);
    }
    else
    {
        dp[l][r] = min(dpSlove(l + 1, r) + mount[l + 1][r] * dis[l][l + 1], dpSlove(r, l + 1) + mount[l + 1][r] * dis[l][r]);
    }
    return dp[l][r];
}
int main()
{
}