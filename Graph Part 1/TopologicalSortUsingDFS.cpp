#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(! vis[it]){
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)
{
    vector<vector<int>> adj(V);
    vector<int> vis(V, 0);

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // u -> v
        adj[u].push_back(v);
    }

    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}