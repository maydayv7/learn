#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    sort(events.begin(), events.end(), [](auto &x, auto &y)
         { return x.first < y.first || (x.first == y.first && x.second > y.second); });

    int maxCustomers = 0, current = 0;
    for (auto &[time, type] : events)
    {
        current += type;
        maxCustomers = max(maxCustomers, current);
    }
    cout << maxCustomers << endl;
}
