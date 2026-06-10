#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int count = 0;
    int sum = 0; // Prefix sum
    map<int, int> prefixCount;
    prefixCount[0] = 1; // If subarray starting from index 0 has sum = x

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        // Previous sum (if exists) = Current sum - x
        if (prefixCount.find(sum - x) != prefixCount.end())
            count += prefixCount[sum - x];

        prefixCount[sum]++;
    }

    cout << count << endl;
}
