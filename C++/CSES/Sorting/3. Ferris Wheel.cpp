#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int &wi : w)
        cin >> wi;
    sort(w.begin(), w.end());

    int gondolas = 0, lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        if (lo == hi || w[lo] + w[hi] > x)
            hi--; // heaviest child goes alone
        else
        {
            lo++;
            hi--; // pair lightest with heaviest
        }
        gondolas++;
    }
    cout << gondolas << endl;
}
