#include <iostream>
int base[25], mp[25][25];
int num, ans = 0, limit;
void traceBack(int t, int count)
{
    if (t >= num)
    {
        ans++;
        return;
    }
    base[t] = 1;
    int temp = count;
    count++;
    for (int i = 0; i < t; i++)
    {
        if (i == 0)
        {
            mp[i][t - i - 1] = base[t - i - 1] ^ base[t - i];
        }
        else
        {
            mp[i][t - i - 1] = mp[i - 1][t - i - 1] ^ mp[i - 1][t - i];
        }
        if (mp[i][t - i - 1])
        {
            count++;
        }
    }
    if (count <= limit && ((t + 2) * (t + 1) / 2 - count <= limit))
    {
        traceBack(t + 1, count);
    }
    base[t] = 0;
    for (int i = 0; i < t; i++)
    {
        if (i == 0)
        {
            mp[i][t - i - 1] = base[t - i - 1] ^ base[t - i];
        }
        else
        {
            mp[i][t - i - 1] = mp[i - 1][t - i - 1] ^ mp[i - 1][t - i];
        }
        if (mp[i][t - i - 1])
        {
            temp++;
        }
    }
    if (temp <= limit && ((t + 2) * (t + 1) / 2 - temp <= limit))
    {
        traceBack(t + 1, temp);
    }
}
int GetAns()
{
    scanf("%d", &num);
    limit = num * (num + 1) / 4;
    if (num * (num + 1) / 2 % 2 == 1)
    {
        return 0;
    }
    traceBack(0, 0);
    return ans;
}
int main()
{
    std::cout << GetAns() << std::endl;
}