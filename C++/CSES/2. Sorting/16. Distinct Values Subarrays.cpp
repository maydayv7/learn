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
    int ans = 0, l = 0;
    for (int r = 0; r < n; r++)
    {
        m[v[r]]++;

        while (m[v[r]] > 1)
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
                m.erase(v[l]);
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << "\n";
}
