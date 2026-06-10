#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

// Ordered Set macro
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range
{
    int x, y, id;
};

signed main()
{
    int n;
    cin >> n;

    vector<Range> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
        v[i].id = i;
    }

    sort(v.begin(), v.end(), [](const Range &a, const Range &b)
         { return a.x < b.x || (a.x == b.x && a.y > b.y); });

    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);
    ordered_set<pair<int, int>> s; // Removes duplicates, so add key

    for (int i = n - 1; i >= 0; i--)
    {
        contains[v[i].id] = s.order_of_key({v[i].y, INT_MAX});
        s.insert({v[i].y, v[i].id});
    }

    s.clear();
    for (int i = 0; i < n; i++)
    {
        int strictly_less = s.order_of_key({v[i].y, -1});
        contained_by[v[i].id] = s.size() - strictly_less;
        s.insert({v[i].y, v[i].id});
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << contained_by[i] << " ";
    cout << "\n";

    return 0;
}
