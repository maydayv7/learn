#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
int cycle_start = -1;
int cycle_end = -1;

bool dfs(int u, int p) {
  visited[u] = true;
  parent[u] = p;
  for (int v : adj[u]) {
    if (v == p)
      continue;

    if (visited[v]) {
      cycle_start = v;
      cycle_end = u;
      return true;
    }

    if (dfs(v, u))
      return true;
  }

  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.assign(n + 1, false);
  parent.assign(n + 1, -1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i)
    if (!visited[i])
      if (dfs(i, -1))
        break;

  if (cycle_start == -1)
    cout << "IMPOSSIBLE\n";
  else {
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int curr = cycle_end; curr != cycle_start; curr = parent[curr])
      cycle.push_back(curr);
    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << "\n";
    for (int i = 0; i < cycle.size(); ++i)
      cout << cycle[i] << " ";
    cout << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
