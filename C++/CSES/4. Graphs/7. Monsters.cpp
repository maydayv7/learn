#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
  int r, c;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir_chars[] = {'U', 'D', 'L', 'R'};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<vector<int>> time(n, vector<int>(m, 1e9));

  Point start;
  queue<Point> q;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'M') {
        q.push({i, j});
        time[i][j] = 0;
      } else if (grid[i][j] == 'A')
        start = {i, j};
    }
  }

  while (!q.empty()) {
    Point curr = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nr = curr.r + dr[i];
      int nc = curr.c + dc[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
        if (time[nr][nc] > time[curr.r][curr.c] + 1) {
          time[nr][nc] = time[curr.r][curr.c] + 1;
          q.push({nr, nc});
        }
      }
    }
  }

  queue<Point> pq;
  pq.push(start);
  vector<vector<int>> player_time(n, vector<int>(m, 1e9));
  vector<vector<int>> from_dir(n, vector<int>(m, -1));
  player_time[start.r][start.c] = 0;
  bool flag = false;
  while (!pq.empty()) {
    Point curr = pq.front();
    if (curr.r == 0 || curr.r == n - 1 || curr.c == 0 || curr.c == m - 1) {
      flag = true;
      break;
    }
    pq.pop();

    for (int i = 0; i < 4; ++i) {
      int nr = curr.r + dr[i];
      int nc = curr.c + dc[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
        int next_time = player_time[curr.r][curr.c] + 1;
        if (next_time < time[nr][nc] && next_time < player_time[nr][nc]) {
          player_time[nr][nc] = next_time;
          from_dir[nr][nc] = i;
          pq.push({nr, nc});
        }
      }
    }
  }

  if (flag) {
    cout << "YES\n";
    string path = "";

    Point curr = pq.front();
    while (curr.r != start.r || curr.c != start.c) {
      int d = from_dir[curr.r][curr.c];
      path += dir_chars[d];
      curr.r -= dr[d];
      curr.c -= dc[d];
    }

    reverse(path.begin(), path.end());
    cout << path.length() << "\n";
    cout << path << "\n";
  } else
    cout << "NO\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
