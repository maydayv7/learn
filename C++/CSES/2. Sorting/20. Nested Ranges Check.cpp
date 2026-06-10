#include <bits/stdc++.h>
#define int long long
using namespace std;

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

    int miny = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i].y >= miny)
            contains[v[i].id] = 1;
        miny = min(miny, v[i].y);
    }

    int maxy = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].y <= maxy)
            contained_by[v[i].id] = 1;
        maxy = max(maxy, v[i].y);
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << contained_by[i] << " ";
    cout << "\n";

    return 0;
}
