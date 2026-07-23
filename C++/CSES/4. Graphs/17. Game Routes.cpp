#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> indeg(n + 1, 0);
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i)
  {
    if (indeg[i] == 0)
      q.push(i);
  }

  vector<int> topo_order;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    topo_order.push_back(u);

    for (int v : adj[u])
    {
      indeg[v]--;
      if (indeg[v] == 0)
        q.push(v);
    }
  }

  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  for (int u : topo_order)
  {
    if (dp[u] == 0)
      continue;

    for (int v : adj[u])
      dp[v] = (dp[v] + dp[u]) % MOD;
  }

  cout << dp[n] << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
