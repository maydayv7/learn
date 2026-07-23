#include <bits/stdc++.h>
using namespace std;

struct Road
{
  int u, v;
  long long cost;

  bool operator<(const Road &other)
  {
    return cost < other.cost;
  }
};

class DSU
{
private:
  vector<int> parent;
  vector<int> size;

public:
  DSU(int n)
  {
    parent.resize(n + 1);
    size.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
      parent[i] = i;
  }

  int find(int i)
  {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[parent[i]]);
  }

  bool unite(int i, int j)
  {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j)
    {
      if (size[root_i] < size[root_j])
        swap(root_i, root_j);
      parent[root_j] = root_i;
      size[root_i] += size[root_j];
      return true;
    }
    return false;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<Road> roads(m);
  for (int i = 0; i < m; i++)
    cin >> roads[i].u >> roads[i].v >> roads[i].cost;

  sort(roads.begin(), roads.end());

  DSU dsu(n);
  long long cost = 0;
  int repaired = 0;
  for (const auto &road : roads)
  {
    if (dsu.unite(road.u, road.v))
    {
      cost += road.cost;
      repaired++;

      if (repaired == n - 1)
        break;
    }
  }

  if (repaired == n - 1)
    cout << cost << "\n";
  else
    cout << "IMPOSSIBLE\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
