#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i)
        cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());

    int t = 0, total = 0;
    for (const auto &task : tasks)
    {
        t += task.first;
        total += (task.second - t);
    }
    cout << total << "\n";
    return 0;
}
