// https://codeforces.com/contest/2024/problem/B

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
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    ll count{0}, left{k};
    if (k <= n)
        count = k;
    else
    {
        for (ll i = 0, j = 0; i < n, left > 0; i++)
        {
            if (i != 0)
                j = arr[i - 1];
            if (left <= (arr[i] - j) * (n - i))
            {
                count += left;
                left = 0;
            }
            else
            {
                count += (arr[i] - j) * (n - i) + 1;
                left -= (arr[i] - j) * (n - i);
            }
        }
    }

    cout << count << "\n";
}

int main()
{
    perf();
    ll loop;
    cin >> loop;
    while (loop--)
        solve();
}
