// https://codeforces.com/contest/2044/problem/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void perf()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> ma, mb;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
        if (mb[a[i]] == 0)
            mb[a[i]]++;
    }

    vector<ll> rand;
    for (int i = 1; i <= n; i++)
        if (ma[i] == 0)
            rand.pb(i);

    ll counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (mb[a[i]] == 1)
        {
            cout << a[i] << " ";
            mb[a[i]]--;
        }
        else
        {
            cout << rand[counter] << " ";
            counter++;
        }
    }

    cout << "\n";
}

int main()
{
    perf();
    ll loop;
    cin >> loop;
    while (loop--)
    {
        solve();
    }
}
