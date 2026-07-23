#include <bits/stdc++.h>
using namespace std;

// 2^60 >= 10^18
const int MAX_JUMP = 60;

void solve()
{
  int n, q;
  cin >> n >> q;

  // up[i][j] -> planet reached from i after 2^j steps
  vector<vector<int>> up(n + 1, vector<int>(MAX_JUMP));

  for (int i = 1; i <= n; ++i)
    cin >> up[i][0];

  // Binary Lifting
  for (int j = 1; j < MAX_JUMP; ++j)
    for (int i = 1; i <= n; ++i)
      up[i][j] = up[up[i][j - 1]][j - 1];

  while (q--)
  {
    int x;
    long long k;
    cin >> x >> k;

    for (int j = 0; j < MAX_JUMP; ++j)
      if ((k >> j) & 1)
        x = up[x][j];

    cout << x << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
