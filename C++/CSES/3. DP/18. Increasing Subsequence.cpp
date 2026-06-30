#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    // Equivalent to sorting piles of cards
    // Place only lower card on higher, otherwise start new pile
    // Tracks best possible ending values for subsequences of every possible length
    vector<int> piles;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(piles.begin(), piles.end(), x);
        if (it == piles.end())
            piles.push_back(x);
        else
            *it = x;
    }

    cout << piles.size() << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
