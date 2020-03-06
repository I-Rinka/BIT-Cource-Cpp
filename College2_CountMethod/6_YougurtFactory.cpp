#include <iostream>
#include <algorithm>
int main()
{
    long long week, fee, money, preMoney = 0x3f3f3f3f, ans = 0;
    scanf("%lld%lld", &week, &fee);
    for (long long i = 0; i < week; i++)
    {
        long long needs;
        std::cin >> money >> needs;
        preMoney = std::min(money, preMoney + fee);
        ans += preMoney * needs;
    }
    std::cout << ans << std::endl;
}