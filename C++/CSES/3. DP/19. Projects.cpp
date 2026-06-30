#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Project
{
    int start;
    int end;
    int reward;
};

void solve()
{
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; ++i)
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;

    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b)
         { return a.end < b.end; });

    // dp[i] -> max profit with first i projects
    vector<int> dp(n + 1, 0);

    vector<int> end_times(n);
    for (int i = 0; i < n; ++i)
        end_times[i] = projects[i].end;

    for (int i = 1; i <= n; ++i)
    {
        int op1 = dp[i - 1];
        int op2 = projects[i - 1].reward;
        auto it = lower_bound(end_times.begin(), end_times.end(), projects[i - 1].start);
        int idx = distance(end_times.begin(), it);
        if (idx > 0)
            op2 += dp[idx];

        dp[i] = max(op1, op2);
    }
    cout << dp[n] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
