#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &v : a)
        cin >> v;

    long long maxSum = a[0], current = a[0];
    for (int i = 1; i < n; i++)
    {
        current = max(a[i], current + a[i]);
        maxSum = max(maxSum, current);
    }
    cout << maxSum << "\n";
}
