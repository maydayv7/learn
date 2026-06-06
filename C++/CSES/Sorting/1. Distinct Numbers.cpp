#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        s.insert(l);
    }

    cout << s.size();
}
