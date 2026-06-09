#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int count = 0;
    int sum = 0; // Prefix sum
    vector<int> prefixCount(n, 0);
    prefixCount[0] = 1;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        int mo = ((sum % n) + n) % n;
        count += prefixCount[mo];
        prefixCount[mo]++;
    }

    cout << count << endl;
}
