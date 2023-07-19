#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> topoQueue;

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                topoQueue.push(i);
            }
        }

        vector<int> ans;

        while (!topoQueue.empty())
        {
            int node = topoQueue.front();
            topoQueue.pop();
            ans.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    topoQueue.push(it);
                }
            }
        }

        return ans;
    }
};