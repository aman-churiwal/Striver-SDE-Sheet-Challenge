class Solution {
public:

    // int solve(int ind1, int ind2, string& text1, string& text2, int m, int n){
    //     if(ind1 >= m || ind2 >= n) return 0;

    //     if(text1[ind1] == text2[ind2]) return 1 + solve(ind1 + 1, ind2 + 1, text1, text2, m, n);
    //     return max(solve(ind1 + 1, ind2, text1, text2, m, n), solve(ind1, ind2 + 1, text1, text2, m, n));
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int ind1 = m - 1; ind1 >= 0; ind1--){
            for(int ind2 = n - 1; ind2 >= 0; ind2--){
                if(text1[ind1] == text2[ind2]) dp[ind1][ind2] = 1 + dp[ind1 + 1][ind2 + 1];
                else dp[ind1][ind2] = max(dp[ind1 + 1][ind2], dp[ind1][ind2 + 1]);
            }
        }

        return dp[0][0];
    }
};