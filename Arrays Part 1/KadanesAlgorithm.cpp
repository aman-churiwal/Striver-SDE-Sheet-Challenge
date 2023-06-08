#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
    long long currSum = arr[0];
    long long maxSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currSum = max(currSum + arr[i], (long long)arr[i]);
        maxSum = max(maxSum, currSum);
    }

    return maxSum < 0 ? 0 : maxSum;
}