#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> pos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--; // 0 index
        pos[arr[i]] = i;
    }

    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (pos[i] > pos[i + 1])
            count++;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--; // 0 index

        int n1 = arr[a];
        int n2 = arr[b];

        set<pair<int, int>> s;
        if (n1 > 0)
            s.insert({n1 - 1, n1});
        if (n1 < n - 1)
            s.insert({n1, n1 + 1});
        if (n2 > 0)
            s.insert({n2 - 1, n2});
        if (n2 < n - 1)
            s.insert({n2, n2 + 1});

        for (auto p : s)
            if (pos[p.first] > pos[p.second])
                count--;

        swap(arr[a], arr[b]);
        swap(pos[n1], pos[n2]);

        for (auto p : s)
            if (pos[p.first] > pos[p.second])
                count++;

        cout << count << "\n";
    }

    return 0;
}
