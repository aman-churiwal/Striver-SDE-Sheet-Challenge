#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 1;
        int suff = 1;
        int maxProduct = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            pre = pre * nums[i];
            suff = suff * nums[n - i - 1];

            maxProduct = max(maxProduct, max(pre, suff));

            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
        }

        return maxProduct;
    }
};