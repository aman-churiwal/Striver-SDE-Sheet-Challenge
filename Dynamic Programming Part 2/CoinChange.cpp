class Solution
{
public:
    int solve(int ind, vector<int> &coins, int amount)
    {
        // int n = coins.size();
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        int notPick = 0 + solve(ind - 1, coins, amount);
        int pick = 1e9;
        if (amount >= coins[ind])
            pick = 1 + solve(ind, coins, amount - coins[ind]);

        return min(notPick, pick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = solve(n - 1, coins, amount);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};