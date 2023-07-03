#include <bits/stdc++.h>

bool solve(int ind, vector<int> &nums, long long sum, long long s, vector<vector<long long>> &dp)
{
    if (ind >= nums.size())
    {
        if (sum == s)
            return true;
        return false;
    }

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    bool pick = solve(ind + 1, nums, sum + nums[ind], s, dp);
    bool notPick = solve(ind + 1, nums, sum, s, dp);

    return dp[ind][sum] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    long long sum = 0;
    for (auto num : arr)
        sum += num;
    vector<vector<long long>> dp(n, vector<long long>(sum + 1, -1));
    return solve(0, arr, 0, k, dp);
}