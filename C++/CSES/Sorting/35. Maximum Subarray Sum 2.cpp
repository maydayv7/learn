#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n + 1, 0);
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        p[i] = p[i - 1] + v[i];
    }

    multiset<int> prefixes;
    int maxs = -LLONG_MAX;
    for (int i = a; i <= n; i++)
    {
        // Subarray sum = p[i]-p[j], a <= i - j <= b
        // i - b <= j <= i - a
        prefixes.insert(p[i - a]);
        if (i - b - 1 >= 0)
        {
            auto it = prefixes.find(p[i - b - 1]);
            if (it != prefixes.end())
                prefixes.erase(it);
        }

        int minpj = *prefixes.begin();
        maxs = max(maxs, p[i] - minpj);
    }

    cout << maxs << "\n";

    return 0;
}
