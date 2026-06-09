#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;

    stack<pair<int, int>> s;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;

        while (!s.empty() && s.top().first >= val)
            s.pop();

        if (s.empty())
            cout << 0 << " ";
        else
            cout << s.top().second << " ";

        s.push({val, i});
    }

    cout << "\n";
    return 0;
}
