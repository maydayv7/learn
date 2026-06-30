#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    // dp[i][v] -> no. of valid prefixes of length i that end with value v (1 <= v <= m)
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (x[0] != 0)
        dp[0][x[0]] = 1;
    else
        for (int v = 1; v <= m; v++)
            dp[0][v] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int v = 1; v <= m; v++)
        {
            if (x[i] != 0 && x[i] != v)
                continue;

            int ways_from_minus_1 = (v - 1 >= 1) ? dp[i - 1][v - 1] : 0;
            int ways_from_same = dp[i - 1][v];
            int ways_from_plus_1 = (v + 1 <= m) ? dp[i - 1][v + 1] : 0;

            dp[i][v] = (ways_from_minus_1 + ways_from_same + ways_from_plus_1) % MOD;
        }
    }

    int ans = 0;
    for (int v = 1; v <= m; v++)
        ans = (ans + dp[n - 1][v]) % MOD;

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
