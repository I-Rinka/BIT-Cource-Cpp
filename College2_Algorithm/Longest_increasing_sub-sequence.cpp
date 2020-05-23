#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
int *dp;
int *IntSequence;
//以第k个数结尾的子序列的长度
int maxLen(int k)
{
    if (dp[k] == -INF)
    {
        int max = -INF;
        int judge = false;
        for (int i = 0; i < k; i++)
        {
            if (dp[i] > max && IntSequence[i] <= IntSequence[k])
            {
                max = maxLen(i);
                judge = true;
            }
        }
        if (judge)
        {
            return dp[k] = max + 1;
        }
        else
        {
            return dp[k] = 1;
        }
    }
    else
    {
        return dp[k];
    }
}
//
int init()
{
    int len;
    scanf("%d", &len);
    IntSequence = (int *)malloc(sizeof(int) * len);
    dp = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            scanf("%d", &IntSequence[i]);
            break;
        }
        scanf("%d,", &IntSequence[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < len; i++)
    {
        dp[i] = -INF;
    }
    return len;
}
int ans(int len)
{
    if (len == 1)
    {
        return 1;
    }
    if (len < 1)
    {
        return 0;
    }
    int max = -INF;
    for (int i = 1; i < len; i++)
    {
        int l = maxLen(i);
        if (l > max)
        {
            max = l;
        }
    }
    return max;
}
int main()
{
    std::cout << ans(init()) << std::endl;
}
