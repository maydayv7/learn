#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
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
    deb(n);

    rep(n)
    {
        cout << i << endl;
    }
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
