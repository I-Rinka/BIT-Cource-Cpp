#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if (!(m && n))
        {
            return 0;
        }
        vector<vector<int>> ans(m, vector<int>(n));
        ans[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
                }
                else if (i - 1 >= 0 && j  == 0)
                {
                    ans[i][j] = ans[i - 1][j] + grid[i][j];
                }
                else if (j - 1 >= 0 && i == 0)
                {
                    ans[i][j] = ans[i][j - 1] + grid[i][j];
                }
            }
        }
        return ans[m - 1][n - 1];
    }
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
};
int main()
{
    vector<vector<int>> in(3);
    in[0].push_back(1);
    in[0].push_back(3);
    in[0].push_back(1);
    in[1].push_back(1);
    in[1].push_back(5);
    in[1].push_back(1);
    in[2].push_back(4);
    in[2].push_back(2);
    in[2].push_back(1);
    Solution an;
    cout << an.minPathSum(in);
}