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

  vector<int> team(n + 1, 0);
  bool possible = true;
  for (int i = 1; i <= n; ++i) {
    if (team[i] == 0) {
      queue<int> q;
      q.push(i);
      team[i] = 1;

      while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int v : adj[curr]) {
          if (team[v] == 0) {
            team[v] = (team[curr] == 1) ? 2 : 1;
            q.push(v);
          } else if (team[v] == team[curr]) {
            possible = false;
            break;
          }
        }
        if (!possible)
          break;
      }
    }
    if (!possible)
      break;
  }

  if (!possible)
    cout << "IMPOSSIBLE\n";
  else {
    for (int i = 1; i <= n; ++i)
      cout << team[i] << " ";
    cout << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
