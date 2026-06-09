#include <bits/stdc++.h>
#define int long long
using namespace std;

bool divide(const vector<int> &v, int k, int sum)
{
    int count = 1, cur = 0;
    for (int x : v)
    {
        if (x > sum)
            return false;

        if (cur + x > sum)
        {
            count++;
            cur = x;
        }
        else
            cur += x;
    }
    return count <= k;
}

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int maxe = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        maxe = max(maxe, v[i]);
        sum += v[i];
    }

    int l = maxe, r = sum, ans = r;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (divide(v, k, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}
