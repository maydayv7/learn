#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    int median = v[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(median - v[i]);
    cout << ans;
}
