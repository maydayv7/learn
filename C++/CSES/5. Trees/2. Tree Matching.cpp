#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
int max_matching = 0;

void dfs(int node, int parent)
{
  for (int child : adj[node])
  {
    if (child != parent)
    {
      dfs(child, node);

      // Post-order processing
      // Always match leaf with parent -> doesn't hurt other potential matches
      if (!visited[child] && !visited[node])
      {
        visited[child] = true;
        visited[node] = true;
        max_matching++;
      }
    }
  }
}

void solve()
{
  cin >> n;
  adj.resize(n + 1);
  visited.assign(n + 1, false);

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << max_matching << "\n";
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
