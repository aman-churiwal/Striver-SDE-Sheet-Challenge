int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);

    for (int wt = weights[0]; wt <= w; wt++)
        prev[wt] = values[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notPick = prev[wt];
            int pick = -1e9;
            if (wt - weights[ind] >= 0)
                pick = values[ind] + prev[wt - weights[ind]];

            curr[wt] = max(notPick, pick);
        }
        prev = curr;
    }

    return prev[w];
}