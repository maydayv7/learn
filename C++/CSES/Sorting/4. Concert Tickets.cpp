#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<long long> tickets;
    for (int i = 0; i < n; i++)
    {
        long long p;
        cin >> p;
        tickets.insert(p);
    }

    for (int i = 0; i < m; i++)
    {
        long long budget;
        cin >> budget;
        // Find largest ticket price <= budget
        auto it = tickets.upper_bound(budget);
        if (it == tickets.begin())
            cout << -1 << "\n"; // no valid ticket
        else
        {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}
