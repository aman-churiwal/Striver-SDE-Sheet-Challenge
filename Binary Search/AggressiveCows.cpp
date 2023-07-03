
bool helper(vector<int> &stalls, int k, int mid)
{
    int cows = 1, lastCowPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastCowPos >= mid)
        {
            cows++;
            lastCowPos = stalls[i];
        }

        if (cows >= k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool isPossible = helper(stalls, k, mid);
        if (isPossible)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}