#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
  Build a DAG where each mountain is a node, and A -> B = valid glide from mountain A to B.
  Instead of checking all pairs, a mountain B can only be reached directly from
  its closest strictly taller neighbor to its left and the other to its right.
  Because we glide only from taller to shorter peaks, graph has no cycles.
  Thus, answer equals longest path.
*/

int n;
vector<int> heights;
vector<vector<int>> adj;
vector<int> dp;

void solve()
{
    cin >> n;
    heights.resize(n);
    adj.resize(n);
    dp.assign(n, 1);

    vector<pair<int, int>> mountains(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
        mountains[i] = {heights[i], i};
    }

    // Closest taller left neighbor
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] <= heights[i])
            st.pop();
        if (!st.empty())
            adj[st.top()].push_back(i);
        st.push(i);
    }

    // Closest taller right neighbor
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] <= heights[i])
            st.pop();
        if (!st.empty())
            adj[st.top()].push_back(i);
        st.push(i);
    }

    sort(mountains.rbegin(), mountains.rend());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = mountains[i].second;
        for (int v : adj[u])
            dp[v] = max(dp[v], dp[u] + 1);
        ans = max(ans, dp[u]);
    }

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
