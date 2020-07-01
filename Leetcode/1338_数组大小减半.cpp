#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool compare(int const a, int const b)
    {
        return a > b;
    }
    int minSetSize(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution S;
    vector<int> input({3, 3, 3, 3, 5, 5, 5, 2, 2, 7});

    S.minSetSize(input);
    return 0;
}
