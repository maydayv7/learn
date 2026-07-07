#include <bits/stdc++.h>
#define int long long
using namespace std;

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

  queue<int> q;
  vector<bool> visited(n + 1, false);
  vector<int> parent(n + 1, -1);
  q.push(1);
  visited[1] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == n)
      break;

    for (int v : adj[curr]) {
      if (!visited[v]) {
        visited[v] = true;
        parent[v] = curr;
        q.push(v);
      }
    }
  }

  if (!visited[n])
    cout << "IMPOSSIBLE\n";
  else {
    vector<int> path;
    for (int curr = n; curr != -1; curr = parent[curr])
      path.push_back(curr);

    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); ++i)
      cout << path[i] << " ";
    cout << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
