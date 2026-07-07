#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
  int x, y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);

  Point start, end;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A')
        start = {i, j};
      else if (grid[i][j] == 'B')
        end = {i, j};
    }
  }

  vector<vector<int>> dirTaken(n, vector<int>(m, -1));
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  queue<Point> q;
  q.push(start);
  visited[start.x][start.y] = true;
  bool found = false;
  while (!q.empty()) {
    Point curr = q.front();
    q.pop();

    if (curr.x == end.x && curr.y == end.y) {
      found = true;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
          grid[nx][ny] != '#') {
        visited[nx][ny] = true;
        dirTaken[nx][ny] = i;
        q.push({nx, ny});
      }
    }
  }

  if (found) {
    cout << "YES\n";

    string path = "";
    Point curr = end;
    while (curr.x != start.x || curr.y != start.y) {
      int d = dirTaken[curr.x][curr.y];
      path += dir[d];
      curr.x -= dx[d];
      curr.y -= dy[d];
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
