#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int current_sum = v[i].first + v[l].first + v[r].first;
            if (current_sum == x)
            {
                cout << v[i].second << " " << v[l].second << " " << v[r].second << "\n";
                return 0;
            }
            if (current_sum < x)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
