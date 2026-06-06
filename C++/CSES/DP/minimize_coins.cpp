#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= x; j++)
            if (j >= c[i])
                dp[j] = min(dp[j], dp[j - c[i]] + 1);

    cout << ((dp[x] == INF) ? -1 : dp[x]) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
