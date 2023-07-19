#include <bits/stdc++.h>
using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    vector<int> curr(n + 1, 0), ahead(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int notTake = ahead[prev_ind + 1];
            int take = -1e9;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                take = arr[ind] + ahead[ind + 1];
            }

            curr[prev_ind + 1] = max(take, notTake);
        }
        ahead = curr;
    }
    return ahead[0];
}