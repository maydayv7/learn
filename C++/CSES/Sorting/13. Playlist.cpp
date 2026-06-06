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

    map<int, int> m;
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++)
    {
        if (m.count(v[r]) && m[v[r]] >= l)
            l = m[v[r]] + 1;
        m[v[r]] = r;
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
