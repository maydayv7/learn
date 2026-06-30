#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &y : x)
        cin >> y;

    // dp[i][j] -> maximum score current player can get from x[i...j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    auto get_dp = [&](int i, int j) -> int
    {
        if (i > j)
            return 0;
        return dp[i][j];
    };
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (len == 1)
                dp[i][j] = x[i];
            else if (len == 2)
                dp[i][j] = max(x[i], x[j]);
            else
            {
                int take_front = x[i] + min(get_dp(i + 2, j), get_dp(i + 1, j - 1));
                int take_back = x[j] + min(get_dp(i + 1, j - 1), get_dp(i, j - 2));
                dp[i][j] = max(take_front, take_back);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
