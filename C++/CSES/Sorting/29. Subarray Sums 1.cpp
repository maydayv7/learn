#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;

    int l = 0, r = -1, sum = 0, count = 0;
    while (r < n)
    {
        while (r < n && sum < x)
            sum += v[++r];

        while (l <= r && sum > x)
            sum -= v[l++];

        if (sum == x)
        {
            count += 1;
            sum -= v[l];
            l += 1;
        }
    }
    return count;
}
