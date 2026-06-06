#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (auto &v : a)
        cin >> v;

    map<long long, int> seen;
    for (int i = 0; i < n; i++)
    {
        long long need = x - a[i];
        if (seen.count(need))
        {
            cout << seen[need] << " " << i + 1 << "\n";
            return 0;
        }
        seen[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
}
