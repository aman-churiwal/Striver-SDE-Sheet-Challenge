#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        if(st.empty()) {
            ans.push_back(-1);
            st.push(nums[i]);
        } else if(st.top() > nums[i]) {
            ans.push_back(st.top());
            st.push(nums[i]);
        } else {
            while(! st.empty() && st.top() <= nums[i]) {
                st.pop();
            } 

            if(st.empty()) {
                ans.push_back(-1);
                st.push(nums[i]);
            } else {
                ans.push_back(st.top());
                st.push(nums[i]);
            }
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}