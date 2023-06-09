vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    if(!root)
        return {};
    
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();

        ans.push_back(node->val);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    return ans;
}