class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n-1;
        int j = -1;
        while(i>=1){
            if(nums[i] <= nums[i-1]){
                i--;
                continue;
            }

            j = i - 1;
            break;
        }
        int maxInd = n-1;

        if(j == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        if(j>=0){
            while(maxInd >= 0 && nums[maxInd]<=nums[j]) maxInd--;

            swap(nums[maxInd], nums[j]);
            reverse(nums.begin()+i, nums.end());
        }
    }
};