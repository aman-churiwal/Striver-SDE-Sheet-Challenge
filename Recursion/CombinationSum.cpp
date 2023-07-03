class Solution
{
public:
    void solve(int ind, int target, vector<int> &candidates, vector<int> &comb, vector<vector<int>> &ans)
    {
        int n = candidates.size();
        if (ind >= n)
        {
            if (target == 0)
                ans.push_back(comb);
            return;
        }

        // Take the current candidate;
        if (candidates[ind] <= target)
        {
            comb.push_back(candidates[ind]);
            solve(ind, target - candidates[ind], candidates, comb, ans);
            comb.pop_back();
        }
        // Not Take the current candidate;
        solve(ind + 1, target, candidates, comb, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(0, target, candidates, comb, ans);
        return ans;
    }
};