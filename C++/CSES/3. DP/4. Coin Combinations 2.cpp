#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    // Outer loop = Coins (in fixed order) -> Combinations
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= x; j++)
            if (j >= c[i])
                dp[j] = (dp[j] + dp[j - c[i]]) % MOD;

    cout << dp[x] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
