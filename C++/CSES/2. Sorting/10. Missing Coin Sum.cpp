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
    sort(v.begin(), v.end());
    int val = 1;
    for (auto i : v)
    {
        if (i > val)
            break;
        val += i;
    }
    cout << val;
}
