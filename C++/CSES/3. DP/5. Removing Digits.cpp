#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp)
        {
            int d = temp % 10;
            if (d > 0)
                dp[i] = min(dp[i], 1 + dp[i - d]);
            temp /= 10;
        }
    }

    cout << dp[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
