#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int> *node, int &X, int &maxVal)
{
    if (!node)
        return;
    solve(node->left, X, maxVal);
    if (node->val <= X)
    {
        maxVal = node->val;
    }
    solve(node->right, X, maxVal);
}

int floorInBST(TreeNode<int> *root, int X)
{
    int maxVal = INT_MAX;
    solve(root, X, maxVal);

    return maxVal;
}