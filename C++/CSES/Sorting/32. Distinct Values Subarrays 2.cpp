#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    map<int, int> m;
    int ans = 0, l = 0, distinct = 0;
    for (int r = 0; r < n; r++)
    {
        m[v[r]]++;
        if (m[v[r]] == 1)
            distinct++;

        while (distinct > k)
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
            {
                distinct--;
                m.erase(v[l]);
            }
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << "\n";
}
