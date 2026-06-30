#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < m; ++i)
        cin >> y[i];

    // dp[i][j] stores the LCS length of x[0...i-1] and y[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << "\n";

    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs.push_back(x[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    for (int k = 0; k < lcs.size(); ++k)
        cout << lcs[k] << " ";
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
