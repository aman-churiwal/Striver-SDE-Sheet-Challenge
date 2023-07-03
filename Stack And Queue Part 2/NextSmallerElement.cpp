vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();
    stack<int> st;

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(A[i]);
            continue;
        }
        if (st.top() < A[i])
        {
            ans.push_back(st.top());
            st.push(A[i]);
            continue;
        }

        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(-1);
            st.push(A[i]);
        }
        else
        {
            ans.push_back(st.top());
            st.push(A[i]);
        }
    }

    return ans;
}