#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    // dp[i] = no. of ways to construct sum = i
    // dp[i] = ∑(dp[i - j]), 1 <= j <= 6
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            if (i >= j)
                dp[i] = (dp[i] + dp[i - j]) % MOD;

    cout << dp[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
