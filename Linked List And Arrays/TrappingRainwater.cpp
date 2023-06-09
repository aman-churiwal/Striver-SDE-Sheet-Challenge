class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftBars(n);
        leftBars[0] = height[0];
        vector<int> rightBars(n);
        rightBars[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            leftBars[i] = max(leftBars[i - 1], height[i]);
        }

        for(int i = n - 2; i >= 0; i--){
            rightBars[i] = max(rightBars[i + 1], height[i]);
        }

        int totalWater = 0;

        for(int i = 0; i < n; i++){
            totalWater += min(leftBars[i], rightBars[i]) - height[i];
        }

        return totalWater;
    }
};