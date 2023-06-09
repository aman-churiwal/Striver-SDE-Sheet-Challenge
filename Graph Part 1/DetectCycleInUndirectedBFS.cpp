#include <bits/stdc++.h>

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n];

    // Adjacency list
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    queue<pair<int, int>>q;
    q.push({0, -1});
    vis[0] = 1;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int node = it.first;
        int parent = it.second;

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, node});
            }
            else if(parent != it) return false;
        }
    }
    return true;
}
