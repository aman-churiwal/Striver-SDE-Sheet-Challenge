class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int currLen = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                currLen++;
            }
            else
            {
                maxLen = max(maxLen, currLen);
                currLen = 0;
            }
        }
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};