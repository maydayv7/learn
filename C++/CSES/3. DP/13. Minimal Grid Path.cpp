#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point
{
    int r, c;
};

void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string result = "";
    result += grid[0][0];

    vector<Point> current_layer;
    current_layer.push_back({0, 0});
    visited[0][0] = true;
    for (int step = 1; step < 2 * n - 1; ++step)
    {
        char min_char = 'Z' + 1;
        vector<Point> next_candidates;
        for (const auto &p : current_layer)
        {
            // Move Right
            if (p.c + 1 < n && !visited[p.r][p.c + 1])
            {
                char ch = grid[p.r][p.c + 1];
                if (ch < min_char)
                {
                    min_char = ch;
                    next_candidates.clear();
                    next_candidates.push_back({p.r, p.c + 1});
                }
                else if (ch == min_char)
                    next_candidates.push_back({p.r, p.c + 1});
                visited[p.r][p.c + 1] = true;
            }
            // Move Down
            if (p.r + 1 < n && !visited[p.r + 1][p.c])
            {
                char ch = grid[p.r + 1][p.c];
                if (ch < min_char)
                {
                    min_char = ch;
                    next_candidates.clear();
                    next_candidates.push_back({p.r + 1, p.c});
                }
                else if (ch == min_char)
                    next_candidates.push_back({p.r + 1, p.c});
                visited[p.r + 1][p.c] = true;
            }
        }

        result += min_char;
        current_layer.clear();
        for (const auto &p : next_candidates)
            if (grid[p.r][p.c] == min_char)
                current_layer.push_back(p);
    }

    cout << result << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
