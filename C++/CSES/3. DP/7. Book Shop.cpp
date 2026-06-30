#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        // Loop backwards to ensure each book is used at most once
        for (int j = x; j >= price[i]; j--)
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);

    cout << dp[x] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
