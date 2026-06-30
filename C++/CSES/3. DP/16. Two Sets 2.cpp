#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int solve()
{
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
        return 0;

    int target = sum / 2;

    // dp[j] -> no. of ways to get sum of j
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // For element 'n' to always be part of 1 set, n-1 iterations (no double-count)
    for (int i = 1; i < n; i++)
        for (int j = target; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % MOD;

    return dp[target];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solve() << "\n";
    return 0;
}
