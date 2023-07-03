void solve(Node *root, int level, vector<int> &leftView)
{
    if (!root)
        return;
    if (leftView.size() == level)
        leftView.push_back(root->data);
    solve(root->left, level + 1, leftView);
    solve(root->right, level + 1, leftView);
}

vector<int> leftView(Node *root)
{
    vector<int> leftView;
    int level = 0;
    solve(root, level, leftView);
    return leftView;
}