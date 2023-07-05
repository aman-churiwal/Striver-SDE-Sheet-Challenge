/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void In(TreeNode *root, vector<int> &ans)
    {
        if (root)
        {
            In(root->left, ans);
            ans.push_back(root->val);
            In(root->right, ans);
        }
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> arr;
        In(root, arr);
        int i = 0, j = arr.size() - 1;

        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == k)
                return true;
            sum > k ? j-- : i++;
        }
        return false;
    }
};