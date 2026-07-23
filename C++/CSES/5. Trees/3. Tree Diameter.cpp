#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> adj;
int max_dist, furthest_node;

void dfs(int node, int parent, int dist)
{
  if (dist > max_dist)
  {
    max_dist = dist;
    furthest_node = node;
  }

  for (int next_node : adj[node])
  {
    if (next_node != parent)
      dfs(next_node, node, dist + 1);
  }
}

void solve()
{
  cin >> n;
  adj.resize(n + 1);

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (n == 1)
  {
    cout << 0 << "\n";
    return;
  }

  // DFS 1
  max_dist = -1;
  dfs(1, 0, 0);

  // DFS 2
  max_dist = -1;
  dfs(furthest_node, 0, 0);

  cout << max_dist << "\n";
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
