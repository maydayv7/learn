#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string x, y;
    cin >> x >> y;
    int m = x.size(), n = y.size();

    // dp[i][j] -> Edit distance for strings of length i and j
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }

    cout << dp[m][n] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
