#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m);
  for (auto &e : edges)
    cin >> e[0] >> e[1] >> e[2];

  vector<int> dist(n + 1, 0);
  vector<int> parent(n + 1, -1);
  int x = -1;

  // Bellman-Ford: n rounds. A relaxation on the n-th round => negative cycle.
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (auto &[a, b, c] : edges)
      if (dist[a] + c < dist[b]) {
        dist[b] = dist[a] + c;
        parent[b] = a;
        x = b;
      }
  }

  if (x == -1) {
    cout << "NO\n";
    return;
  }

  // Walk back n steps to guarantee we are on the cycle.
  for (int i = 0; i < n; ++i)
    x = parent[x];

  // Collect the cycle.
  vector<int> cycle;
  for (int v = x;; v = parent[v]) {
    cycle.push_back(v);
    if (v == x && cycle.size() > 1)
      break;
  }
  reverse(cycle.begin(), cycle.end());

  cout << "YES\n";
  for (int i = 0; i < (int)cycle.size(); ++i)
    cout << cycle[i] << " \n"[i + 1 == (int)cycle.size()];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
