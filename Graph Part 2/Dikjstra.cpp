vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int wt = it[1];
            if (currDist + wt < dist[adjNode])
            {
                dist[adjNode] = currDist + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}