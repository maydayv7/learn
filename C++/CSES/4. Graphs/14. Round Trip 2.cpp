#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> state; // 0 = unvisited, 1 = processing, 2 = visited
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u)
{
  state[u] = 1;

  for (int v : adj[u])
  {
    if (state[v] == 0)
    {
      parent[v] = u;
      if (dfs(v))
        return true;
    }
    else if (state[v] == 1)
    {
      cycle_end = u;
      cycle_start = v;
      return true;
    }
  }

  state[u] = 2;
  return false;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  state.assign(n + 1, 0);
  parent.assign(n + 1, -1);
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; ++i)
  {
    if (state[i] == 0)
    {
      if (dfs(i))
        break;
    }
  }

  if (cycle_start == -1)
  {
    cout << "IMPOSSIBLE\n";
    return;
  }

  vector<int> cycle;
  cycle.push_back(cycle_start);
  for (int v = cycle_end; v != cycle_start; v = parent[v])
    cycle.push_back(v);
  cycle.push_back(cycle_start);
  reverse(cycle.begin(), cycle.end());

  cout << cycle.size() << "\n";
  for (int i = 0; i < (int)cycle.size(); ++i)
    cout << cycle[i] << " ";
  cout << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
