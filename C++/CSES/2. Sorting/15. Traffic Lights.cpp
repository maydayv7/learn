#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int x, n;
    cin >> x >> n;
    vector<int> v(n);
    for (int &y : v)
        cin >> y;

    set<int> pos{0, x};
    for (int y : v)
        pos.insert(y);

    vector<int> gap(n);
    int l = 0, maxg = 0;
    for (int y : pos)
    {
        maxg = max(maxg, y - l);
        l = y;
    }
    gap.back() = maxg;

    for (int i = n - 1; i > 0; i--)
    {
        pos.erase(v[i]);
        auto it = pos.upper_bound(v[i]);
        auto pre = prev(it);
        maxg = max(maxg, *it - *pre);
        gap[i - 1] = maxg;
    }

    for (int i = 0; i < gap.size(); i++)
        cout << gap[i] << " ";
}
