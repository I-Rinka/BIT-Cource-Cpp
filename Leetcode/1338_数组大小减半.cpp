#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool compare(int const a, int const b)
    {
        return a < b;
    }
    int minSetSize(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        priority_queue<int, vector<int>, less<int>> A;
        int plus = 1;
        int now = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (now != arr[i] )
            {
                now = arr[i];
                A.push(plus);
                plus = 1;
            }
            else
            {
                plus++;
            }
            if (i == arr.size()-1)
            {
                A.push(plus);
            }
            
        }
        int size = 0;
        int ans = 0;
        while (!A.empty())
        {
            size += A.top();
            A.pop();
            ans++;
            if (size >= arr.size() / 2)
            {
                return ans;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution S;
    vector<int> input({1000,1000,3,7});

    cout << S.minSetSize(input);
    return 0;
}
