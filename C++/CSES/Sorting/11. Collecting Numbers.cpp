#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        a[l - 1] = i;
    }

    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            count++;
    }

    cout << count << endl;
}
