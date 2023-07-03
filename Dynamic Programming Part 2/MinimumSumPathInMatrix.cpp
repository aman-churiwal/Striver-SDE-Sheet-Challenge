#include <bits/stdc++.h>
using namespace std;

int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int n = grid.size(), m = grid[0].size();

    if (row >= n || col >= m)
        return 1e9;
    if (row == n - 1 && col == m - 1)
        return grid[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];

    int right = grid[row][col] + solve(row, col + 1, grid, dp);
    int down = grid[row][col] + solve(row + 1, col, grid, dp);

    return dp[row][col] = min(right, down);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = m - 1; col >= 0; col--)
        {
            if (row == n - 1 && col == m - 1)
            {
                dp[row][col] = grid[n - 1][m - 1];
                continue;
            }

            int right = grid[row][col];
            int down = grid[row][col];

            if (col + 1 < n)
                right += dp[row][col + 1];
            else
                right += 1e9;
            if (row + 1 < m)
                down += dp[row + 1][col];
            else
                down += 1e9;

            dp[row][col] = min(right, down);
        }
    }

    return dp[0][0];
}