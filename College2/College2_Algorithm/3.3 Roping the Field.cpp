#include <iostream>
#include <cstring>
using namespace std;
struct position
{
    int x;
    int y;
};
position *pile, *round;
int N, G, radius;
void input()
{
    //输入桩的数量N，怪圈数量G，半径R
    scanf("%d%d%d", &N, &G, &radius);
    pile = (position *)malloc(sizeof(position) * N);
    round = (position *)malloc(sizeof(position) * G);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &pile[i].x, &pile[i].y);
    }
    for (int i = 0; i < G; i++)
    {
        scanf("%d%d", &round[i].x, &round[i].y);
    }
}
double distanceSquare(double A, double B, double c, double x0, double y0)
{
    return (A * x0 + B * y0 + c) * (A * x0 + B * y0 + c) / (A * A + B * B);
}
//判断能否有连线
int judge(position &a, position &b)
{
    double x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
    double R = radius * radius;
    double A = x2 - x1, B = y1 - y2, c = x1 * (y2 - y1) - y1 * (x2 - x1);
    bool judge = true;
    for (int i = 0; i < G; i++)
    {
        if (R >= distanceSquare(A, B, c, round[i].x, round[i].y) && ((round[i].x - x1) * (round[i].x - x2) + (round[i].y - y1) * (round[i], y1 - y2) < 0))
        {
            judge = false;
        }
    }
    if (judge)
    {
        return 1;
    }
    return 0;
}
int **isConnectAble;
int **Dp;
int ans()
{
    if (N <= 2)
    {
        return 0;
    }
    isConnectAble = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        isConnectAble[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++)
        {
            if (i == j || abs(i - j) <= 1)
            {
                isConnectAble[i][j] = 0;
            }
            else
            {
                isConnectAble[i][j] = judge(pile[i], pile[j]);
            }
        }
    }
    Dp = (int **)malloc(sizeof(int *) * (N - 2));
    for (int i = 0; i < N - 2; i++)
    {
        Dp[i] = (int *)malloc(sizeof(int) * (N - 2));
        memset(Dp[i], 0, (N - 2) * sizeof(int));
    }
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < N - 2; j++)
        {
            int x = i + j, y = i + j;
            if (x - 1 >= 0 && y - 1 >= 0)
            {
                Dp[x][y] = max(Dp[x - 1][y], Dp[x][y - 1]) + isConnectAble[x + 2][y];
            }
            else if (x == 0 && y == 0)
            {
                Dp[x][y] = isConnectAble[x + 2][y];
            }
            else if (x == 0)
            {
                Dp[x][y] = Dp[x][y - 1] + isConnectAble[x + 2][y];
            }
            else if (y == 0)
            {
                Dp[x][y] = Dp[x - 1][y] + isConnectAble[x + 2][y];
            }
        }
    }
    return Dp[0][N - 2];
}
int main()
{
    input();
    cout << ans() << endl;
}
// int ans1 = ans();