class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        if (n == 1)
            return {{1}};
        vector<vector<int>> ans;

        ans.push_back({1});
        ans.push_back({1, 1});

        for (int i = 2; i < n; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j <= i - 1; j++)
            {
                temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};