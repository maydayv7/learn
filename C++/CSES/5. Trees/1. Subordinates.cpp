#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> subordinates;

void dfs(int node)
{
  for (int child : adj[node])
  {
    dfs(child);
    subordinates[node] += subordinates[child] + 1;
  }
}

void solve()
{
  cin >> n;
  adj.resize(n + 1);
  subordinates.assign(n + 1, 0);

  for (int i = 2; i <= n; i++)
  {
    int boss;
    cin >> boss;
    adj[boss].push_back(i);
  }

  dfs(1);
  for (int i = 1; i <= n; i++)
    cout << subordinates[i] << (i == n ? "" : " ");
  cout << "\n";
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
