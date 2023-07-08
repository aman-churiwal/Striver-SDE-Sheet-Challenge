#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    int n = kArrays.size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        auto arr = kArrays[i];

        for (int j = 0; j < arr.size(); j++)
        {
            pq.push(arr[j]);
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}