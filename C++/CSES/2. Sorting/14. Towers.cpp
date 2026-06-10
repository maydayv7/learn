#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, k;
    cin >> n;
    multiset<int> ans;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        auto it = ans.upper_bound(k);
        if (it == ans.end())
            ans.insert(k);
        else
        {
            ans.erase(it);
            ans.insert(k);
        }
    }
    cout << ans.size();
    return 0;
}
