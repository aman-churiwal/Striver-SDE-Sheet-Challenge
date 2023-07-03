
int helper(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 0;
    }
    if (ans < m)
        return 1;
    return 2;
}

int NthRoot(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midNumFlag = helper(mid, n, m);
        if (midNumFlag == 2)
            return mid;
        else if (midNumFlag == 1)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}