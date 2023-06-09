bool dfs(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]) {
            if(dfs(it, node, adj, vis) == true) return true;
        }
        else if(it != parent) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];

    // Adjacency list
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    int vis[n+1] = {0};
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis) == true) return "Yes";
        }
    }
    return "No";
}
