#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            while (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                while (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (j < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of target " << endl;
    int target;
    cin >> target;
    vector<vector<int>> ans = obj.fourSum(nums, target);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[0].size(); j++)
        {
            if (j == ans[0].size() - 1)
            {
                cout << ans[i][j];
                continue;
            }
            cout << ans[i][j] << ",";
        }
        if (i == ans.size() - 1)
        {
            cout << "]";
            continue;
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}