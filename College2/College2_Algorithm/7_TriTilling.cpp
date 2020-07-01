#include <iostream>
long long solve(int turns)
{
    if (turns % 2 == 1)
    {
        return 0;
    }
    long long dp[turns / 2 + 1];
    dp[1] = 3;
    dp[2] = 11;
    for (int i = 3; i <= turns / 2; i++)
    {
        dp[i] = 4 * dp[i - 1] - dp[i - 2];
    }
    return dp[turns / 2];
}
int main()
{
    int turns;
    while (true)
    {
        scanf("%d", &turns);
        if (turns == -1)
        {
            break;
        }
        printf("%lld\n", solve(turns));
    }
}