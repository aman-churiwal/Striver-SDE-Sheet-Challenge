#include <bits/stdc++.h>
using namespace std;

int solve(int ind1, int ind2, string str1, string str2, vector<vector<int>> &dp)
{
    if (ind1 < 0)
        return ind2 + 1;
    if (ind2 < 0)
        return ind1 + 1;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (str1[ind1] == str2[ind2])
        return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, str1, str2, dp);
    int insert = 1 + solve(ind1, ind2 - 1, str1, str2, dp);
    int del = 1 + solve(ind1 - 1, ind2, str1, str2, dp);
    int replace = 1 + solve(ind1 - 1, ind2 - 1, str1, str2, dp);

    return dp[ind1][ind2] = min(del, min(insert, replace));
}
int editDistance(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<int> curr(n + 1, 0), prev(n + 1, 0);

    for (int ind2 = 0; ind2 <= n; ind2++)
    {
        prev[ind2] = ind2;
    }

    for (int ind1 = 1; ind1 <= m; ind1++)
    {
        curr[0] = ind1;
        for (int ind2 = 1; ind2 <= n; ind2++)
        {
            if (str1[ind1 - 1] == str2[ind2 - 1])
            {
                curr[ind2] = prev[ind2 - 1];
                continue;
            }
            int insert = 1 + curr[ind2 - 1];
            int del = 1 + prev[ind2];
            int replace = 1 + prev[ind2 - 1];

            curr[ind2] = min(del, min(insert, replace));
        }
        prev = curr;
    }

    return curr[n];
}