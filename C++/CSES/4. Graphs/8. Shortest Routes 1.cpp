#include <bits/stdc++.h>
#define int long long
using namespace std;

// Djikstra
void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  vector<int> dist(n + 1, LLONG_MAX);
  // {distance, city}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u])
      continue;

    for (auto [v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << dist[i] << " \n"[i == n];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
