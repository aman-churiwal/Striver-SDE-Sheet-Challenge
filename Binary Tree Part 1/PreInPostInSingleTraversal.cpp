void solve(BinaryTreeNode<int> *node, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    if (!node)
        return;

    pre.push_back(node->data);
    solve(node->left, pre, in, post);
    in.push_back(node->data);
    solve(node->right, pre, in, post);
    post.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<int> pre, in, post;
    solve(root, pre, in, post);
    return {in, pre, post};
}