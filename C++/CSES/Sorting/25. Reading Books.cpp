#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int &t : v)
    {
        cin >> t;
        sum += t;
    }

    sort(v.begin(), v.end());
    cout << max(sum, 2 * v[n - 1]);
    return 0;
}
