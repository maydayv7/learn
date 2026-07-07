#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited) {
  visited[node] = true;
  for (int v : adj[node])
    if (!visited[v])
      dfs(v, adj, visited);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n + 1, false);
  vector<int> components;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      components.push_back(i);
      dfs(i, adj, visited);
    }
  }

  int ans = components.size() - 1;
  cout << ans << "\n";

  for (int i = 1; i < components.size(); ++i)
    cout << components[0] << " " << components[i] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
