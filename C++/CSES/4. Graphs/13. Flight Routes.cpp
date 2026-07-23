#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  // {neighbor, weight}
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  // {current path cost, node}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> count_pop(n + 1, 0);
  vector<int> ans;
  pq.push({0, 1});
  while (!pq.empty())
  {
    auto [d, u] = pq.top();
    pq.pop();
    if (count_pop[u] >= k)
      continue;
    count_pop[u]++;

    if (u == n)
    {
      ans.push_back(d);
      if ((int)ans.size() == k)
        break;
    }

    for (auto &[v, w] : adj[u])
      if (count_pop[v] < k)
        pq.push({d + w, v});
  }

  for (int i = 0; i < k; ++i)
    cout << ans[i] << " ";
  cout << "\n";
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
