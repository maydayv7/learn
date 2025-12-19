// https://codeforces.com/contest/2133/problem/C

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "./C++/debug.h"
#endif

#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define sm multiset<int>
#define pq priority_queue<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define sp(x) setprecision(x)
#define sz(x) ((int)(x).size())
#define sb(x) __builtin_popcountll(x)
#define lsb(x) __builtin_ctzll(x)
#define msb(x) (63 - __builtin_clzll(x))

#define rep(n) for (int i = 0; i < (n); i++)
#define rep2(n) for (int i = 1; i < (n); i++)
#define read(v, n)                \
    for (int i = 0; i < (n); i++) \
    cin >> v[i]
#define read2(v, n)                \
    for (int i = 1; i <= (n); i++) \
    cin >> v[i]

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<pii> v(n);

    rep(n)
    {
        cout << "? " << i + 1 << " " << n;
        for (int k = 1; k <= n; k++)
            cout << " " << k;
        cout << endl;
        cout.flush();

        int l;
        cin >> l;
        v[i] = {i + 1, l};
    }

    auto comp = [](pii a, pii b)
    { return a.second > b.second; };
    sort(all(v), comp);

    vi ans;
    int prev = v[0].first;
    ans.pb(prev);
    int len = v[0].second;

    for (int i = 1; i < n && len > 1; i++)
    {
        if (v[i].second == len - 1)
        {
            cout << "? " << prev << " 2 " << prev << " " << v[i].first << endl;
            cout.flush();

            int l;
            cin >> l;
            if (l == 2)
            {
                prev = v[i].first;
                ans.pb(prev);
                len--;
            }
        }
    }

    cout << "! " << sz(ans);
    for (auto x : ans)
        cout << " " << x;
    cout << endl;
    cout.flush();
    return;
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
