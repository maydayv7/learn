#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  // dist[u][coupon]: min cost to reach u with or without using coupon
  vector<array<int, 2>> dist(n + 1, {INF, INF});

  // {cost, city, coupon}
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
  dist[1][0] = 0;
  pq.push({0, 1, 0});
  while (!pq.empty()) {
    auto [d, u, k] = pq.top();
    pq.pop();

    if (d > dist[u][k])
      continue;

    for (auto [v, c] : adj[u]) {
      if (d + c < dist[v][k]) {
        dist[v][k] = d + c;
        pq.push({dist[v][k], v, k});
      }
      if (k == 0 && d + c / 2 < dist[v][1]) {
        dist[v][1] = d + c / 2;
        pq.push({dist[v][1], v, 1});
      }
    }
  }

  cout << min(dist[n][0], dist[n][1]) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
