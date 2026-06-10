#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int flag = -1;
    while (!q.empty())
    {
        int el = q.front();
        q.pop();
        if (flag == 1)
            cout << el << " ";
        else
            q.push(el);
        flag = -flag;
    }
    return 0;
}
