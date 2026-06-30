#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    // dp[mask] = {rides, last_weight}
    // last_weight -> min weight loaded on last ride for optimal config
    int states = 1 << n;
    vector<pair<int, int>> dp(states, {n + 1, 0});
    dp[0] = {1, 0};
    for (int mask = 0; mask < states; ++mask)
    {
        if (dp[mask].first > n)
            continue;

        int current_rides = dp[mask].first;
        int current_weight = dp[mask].second;

        for (int i = 0; i < n; ++i)
        {
            if (!(mask & (1 << i)))
            {
                int next_mask = mask | (1 << i);
                int next_rides = current_rides;
                int next_weight = current_weight + w[i];
                if (next_weight > x)
                {
                    next_rides++;
                    next_weight = w[i];
                }

                pair<int, int> candidate = {next_rides, next_weight};
                if (candidate < dp[next_mask])
                    dp[next_mask] = candidate;
            }
        }
    }
    cout << dp[states - 1].first << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
