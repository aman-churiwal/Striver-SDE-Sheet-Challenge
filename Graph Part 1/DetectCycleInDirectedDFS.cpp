bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector <int>& pathVis){
  vis[node] = 1;
  pathVis[node] = 1;

  for(auto it: adj[node]){
    if(!vis[it]){
      if(dfs(it, adj, vis, pathVis) == true) return true;
    } else if(pathVis[it]) return true;
  }

  pathVis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n + 1);
  vector <int> vis(n + 1, 0);
  vector <int> pathVis(n + 1, 0);

  for(auto it: edges){
    adj[it.first].push_back(it.second);
  }

  for(int i = 0; i < n; i++){
    if(dfs(i, adj, vis, pathVis) == true) return true;
  }

  return false;

}