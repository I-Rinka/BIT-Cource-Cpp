#include <iostream>
#include <vector>
int len;
int *intSe;
void init()
{
    scanf("%d", &len);
    intSe = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &intSe[i]);
    }
}
int GetAns()
{
    int sum = 0, ans = intSe[0], p = -1, p2 = -1;
    for (int i = 0; i < len; i++)
    {
        sum += intSe[i];
        if (sum > ans)
        {
            ans = sum;
            p = i;
        }
        if (sum <= 0)
        {
            sum = 0;
        }
    }
    if (p == -1 || len <= 0 || ans <= 0)
    {
        return -1;
    }
    for (int i = p; i >= 0; i--)
    {
        ans -= intSe[i];
        if (ans == 0)
        {
            p2 = i;
        }
    }
    for (int i = p2; i <= p; i++)
    {
        if (i == p)
        {
            printf("%d\n", intSe[i]);
        }
        else
        {
            printf("%d ", intSe[i]);
        }
    }
    return 0;
}
int main()
{
    init();
    GetAns();
}