void solve(TreeNode *node, int level, int &maxHeight)
{
    maxHeight = max(maxHeight, level);
    if (node->left)
        solve(node->left, level + 1, maxHeight);
    if (node->right)
        solve(node->right, level + 1, maxHeight);
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int level = 1;
    int maxHeight = INT_MIN;
    solve(root, level, maxHeight);
    return maxHeight;
}