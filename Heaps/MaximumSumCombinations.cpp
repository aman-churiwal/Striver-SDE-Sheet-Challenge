#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    int n = N;
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    st.insert({n - 1, n - 1});

    for (int c = 0; c < K; c++)
    {
        auto it = pq.top();
        pq.pop();
        ans.push_back(it.first);

        int i = it.second.first;
        int j = it.second.second;

        if (st.find({i - 1, j}) == st.end())
        {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            st.insert({i - 1, j});
        }

        if (st.find({i, j - 1}) == st.end())
        {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            st.insert({i, j - 1});
        }
    }

    return ans;
}