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
class Solution {
public:

    void solve(TreeNode* node, vector<int>& postorder){
        if(!node) return;
        solve(node->left, postorder);
        solve(node->right, postorder);
        postorder.push_back(node->val);
    } 

    vector<int> postOrderTraversal(TreeNode* root) {
        vector<int> postorder;
        solve(root, postorder);
        return postorder;
    }
};