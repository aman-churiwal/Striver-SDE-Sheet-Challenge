class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq{nums.begin(), nums.end()};

        while(pq.size() != n-k+1) pq.pop();
        return pq.top();
    }
};