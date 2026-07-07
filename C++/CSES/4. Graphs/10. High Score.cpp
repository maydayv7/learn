#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

// Bellman-Ford
void solve() {
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m);
  for (auto &e : edges)
    cin >> e[0] >> e[1] >> e[2];

  vector<int> dist(n + 1, -INF);
  dist[1] = 0;
  for (int i = 1; i < n; ++i)
    for (auto &[a, b, x] : edges)
      if (dist[a] != -INF && dist[a] + x > dist[b])
        dist[b] = dist[a] + x;

  // Positive Cycle
  vector<bool> cycle(n + 1, false);
  for (int i = 0; i < n; ++i)
    for (auto &[a, b, x] : edges)
      if (dist[a] != -INF && dist[a] + x > dist[b]) {
        dist[b] = dist[a] + x;
        cycle[b] = true;
      }

  vector<vector<int>> adj(n + 1);
  for (auto &[a, b, x] : edges)
    adj[a].push_back(b);

  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (cycle[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
      if (!cycle[v]) {
        cycle[v] = true;
        q.push(v);
      }
  }

  cout << (cycle[n] ? -1 : dist[n]) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
