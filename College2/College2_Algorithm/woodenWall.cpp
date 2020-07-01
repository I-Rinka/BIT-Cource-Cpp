#include <iostream>
using namespace std;
const int maxN = 100000;
long long h[maxN];
long long getAns()
{
    int n;
    long long ans = 0;
    while (true)
    {
        ans = 0;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++)
        {
            long long temp = 0;
            long minH = h[i];
            for (int j = i; j < n; j++)
            {
                if (h[j] < minH)
                {
                    minH = h[j];
                }
                if (minH * (n - i) < ans)
                {
                    break;
                }
                temp = minH * (j - i + 1);

                if (temp > ans)
                {
                    ans = temp;
                }
            }
        }
        cout << ans << endl;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    getAns();
    return 0;
}
