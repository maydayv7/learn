#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            if (row[j] == '*')
                dp[j] = 0;
            else
            {
                if (i == 0 && j == 0)
                    dp[j] = 1;
                else if (i == 0)
                    dp[j] = dp[j - 1];
                else if (j > 0)
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
