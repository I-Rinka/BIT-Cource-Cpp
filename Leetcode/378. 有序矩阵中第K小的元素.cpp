#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int find(vector<vector<int>> &matrix, int mid) //mid和比mid小的会被分到左边
    {
        int m = matrix.size() - 1;
        int n = 0;
        int num = 0;
        while (1)
        {
            if (n >= matrix[0].size())
            {
                num += matrix[0].size();
                m--;
            }
            else
            {
                if (matrix[m][n] > mid)
                {
                    m--;
                    num += n;
                }
                else
                {
                    n++;
                }
            }
            if (m < 0)
            {
                break;
            }
        }
        return num;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int l = matrix[0][0];
        int r = matrix[matrix.size() - 1][matrix[0].size() - 1];
        while (l < r)
        {
            int mid = (l + r) / 2;
            int num = find(matrix, mid);
            if (k > num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> v({{1, 5, 9},
                           {10, 11, 13},
                           {12, 13, 15}});
    cout << s.kthSmallest(v, 8);
    return 0;
}
