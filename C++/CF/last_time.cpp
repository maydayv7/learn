// https://codeforces.com/contest/2126/problem/D

#include <bits/stdc++.h>

#define int long long
using namespace std;

#define PB push_back
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    int coin = k;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (coin >= v[i][0] && coin < v[i][1])
            coin = max(coin, v[i][2]);
    }

    cout << coin << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int loop;
    cin >> loop;
    while (loop--)
        solve();
}
