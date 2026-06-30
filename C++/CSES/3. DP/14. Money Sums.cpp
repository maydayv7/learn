#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_SUM = 100005;

void solve()
{
    int n;
    cin >> n;

    bitset<MAX_SUM> dp;
    dp[0] = 1; // Base case
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dp |= (dp << x);
    }

    vector<int> sums;
    for (int i = 1; i < MAX_SUM; i++)
        if (dp[i])
            sums.push_back(i);

    cout << sums.size() << "\n";
    for (int i = 0; i < sums.size(); i++)
        cout << sums[i] << " ";
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
