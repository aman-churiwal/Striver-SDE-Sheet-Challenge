/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/
bool solve(BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2)
{
    if (!node1 && !node2)
        return true;
    if (!node1 || !node2)
        return false;

    return (node1->data == node2->data && solve(node1->left, node2->right) && solve(node1->right, node2->left));
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    return solve(root->left, root->right);
}