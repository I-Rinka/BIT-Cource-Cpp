#include <iostream>
using namespace std;
int timeOfTask[14][14];
int visited[14] = {0};
int minTime[14];
int n;
int ans = 10000;
int temp = 0;
int remain = 0;
void dfs(int th)
{
    if (th >= n)
    {
        if (temp < ans)
        {
            ans = temp;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            remain -= minTime[i];
            temp = temp + timeOfTask[th][i];
            if (temp >= ans || temp + remain >= ans)
            {
                temp = temp - timeOfTask[th][i];
                remain += minTime[i];
                continue;
            }
            visited[i] = 1;
            dfs(th + 1);
            temp = temp - timeOfTask[th][i];
            remain += minTime[i];
            visited[i] = 0;
        }
    }
}
int GetAns()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> timeOfTask[i][j];
        }
    }
    for (int j = 0; j < n; j++)
    {
        minTime[j] = timeOfTask[0][j];
        for (int i = 1; i < n; i++)
        {
            if (timeOfTask[i][j] < minTime[j])
            {
                minTime[j] = timeOfTask[i][j];
            }
        }
        remain += minTime[j];
    }
    dfs(0);
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    GetAns();
    return 0;
}
