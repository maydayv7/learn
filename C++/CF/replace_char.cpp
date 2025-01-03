// https://codeforces.com/problemset/problem/2047/B

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
    string s;
    cin >> s;

    map<char, ll> m;
    for (ll i = 0; i < n; i++)
        m[s[i]]++;

    ll min{n}, max{-1};
    char c;
    for (auto ptr = m.begin(); ptr != m.end(); ptr++) // or use (auto ptr : m), and access using ptr.<identifier>
    {
        if (max < ptr->second)
        {
            max = ptr->second;
            c = ptr->first;
        }
        if (min > ptr->second)
            min = ptr->second;
    }

    for (ll i = 0; i < n; i++)
    {
        if (m[s[i]] == min && s[i] != c)
        {
            s[i] = c;
            break;
        }
    }

    cout << s << "\n";
}

int main()
{
    perf();
    ll loop;
    cin >> loop;
    while (loop--)
        solve();
}
