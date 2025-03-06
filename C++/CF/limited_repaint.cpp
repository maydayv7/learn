// https://codeforces.com/problemset/problem/2070/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

#define F first
#define S second
#define PB push_back
#define FOR(n) for (int i = 0; i < n; i++)

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a[n];
    FOR(n)
    cin >> a[i];

    ll l = 0, r = pow(10, 9), m, ans = -1;
    while (l <= r)
    {
        m = (l + r) / 2;

        ll count = 0;
        char last = 'R';
        FOR(n)
        {
            if (a[i] > m)
            {
                if (s[i] == 'B' && last != 'B')
                    count++;
                last = s[i];
            }
        };

        if (count <= k)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll loop;
    cin >> loop;
    while (loop--)
        solve();
}
