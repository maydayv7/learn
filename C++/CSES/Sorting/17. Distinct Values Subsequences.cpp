#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main()
{
    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }

    int ans = 1;
    for (auto const &[u, v] : m)
        ans = (ans * (v + 1)) % MOD;

    // Empty subsequence
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << "\n";
}
