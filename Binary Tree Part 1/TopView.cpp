class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> nodes;
        vector <int> ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(! q.empty()){
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int level = it.second;
            
            if(nodes.find(level) == nodes.end()) nodes[level] = node->data;
            
            if(node->left) q.push({node->left, level - 1});
            if(node->right) q.push({node->right, level + 1});
        }
        
        for(auto it: nodes){
            ans.push_back(it.second);
        }
        return ans;
    }

};