#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e18;

struct Edge
{
  int to;
  long long cost;
};

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<Edge>> adj(n + 1);
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
  }

  vector<long long> price(n + 1, INF);
  vector<long long> count(n + 1, 0);
  vector<int> min_flights(n + 1, 1e9);
  vector<int> max_flights(n + 1, -1);

  // {current price, city}
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

  price[1] = 0;
  count[1] = 1;
  min_flights[1] = 0;
  max_flights[1] = 0;
  pq.push({0, 1});

  while (!pq.empty())
  {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > price[u])
      continue;

    for (const auto &[v, c] : adj[u])
    {
      if (price[u] + c < price[v])
      {
        price[v] = price[u] + c;
        count[v] = count[u];
        min_flights[v] = min_flights[u] + 1;
        max_flights[v] = max_flights[u] + 1;
        pq.push({price[v], v});
      }
      else if (price[u] + c == price[v])
      {
        count[v] = (count[v] + count[u]) % MOD;
        min_flights[v] = min(min_flights[v], min_flights[u] + 1);
        max_flights[v] = max(max_flights[v], max_flights[u] + 1);
      }
    }
  }

  cout << price[n] << " " << count[n] << " " << min_flights[n] << " " << max_flights[n] << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
