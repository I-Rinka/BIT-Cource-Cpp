#include <iostream>
using namespace std;
//最后的总数
int ans = 0, limt = 0, num;
//第一层
int x[25], map[25][25];
int countNumber(int c, int base)
{
    for (int i = 0; i < base - 1; i++)
    {
        for (int j = 0; j < base - 1 - i; j++)
        {
            if (i == 0)
            {
                map[i][j] = x[j] ^ x[j + 1];
            }
            else
            {
                map[i][j] = map[i - 1][j] ^ map[i - 1][j + 1];
            }
            if (map[i][j] == 1)
            {
                c++;
            }
        }
    }
    return c;
}
void traceBack(int n, int count)
{
    if (n == num)
    {
        if (countNumber(count, n) == limt)
        {
            ans++;
        }
        return;
    }
    x[n] = 1;
    if ((count + 1) < limt || ((count + 1 == limt) && num == 3))
    {
        if (countNumber(count, n) < limt)
        {
            traceBack(n + 1, count + 1);
        }
    }
    x[n] = 0;
    traceBack(n + 1, count);
}
int GetAnswer()
{
    scanf("%d", &num);
    limt = num * (num + 1) / 4;
    if (num * (num + 1) % 2 == 1)
    {
        return 0;
    }
    traceBack(0, 0);
    return ans;
}
int main()
{
    cout << GetAnswer() << endl;
}