class Solution
{
public:
    
    void solve(int ind, vector<int>& arr, int& N, int sum, vector<int>& ans){
        if(ind>=N){
            ans.push_back(sum);
            return;
        }
        
        
        // Not Take
        solve(ind+1, arr, N, sum, ans);
        solve(ind+1, arr, N, sum + arr[ind], ans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum = 0;
        vector<int> ans;
        solve(0, arr, N, sum, ans);
        return ans;
    }
};