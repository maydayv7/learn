#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (auto &[s, e] : movies)
        cin >> s >> e;

    sort(movies.begin(), movies.end(), [](auto &x, auto &y)
         { return x.second < y.second; });

    int count = 0, lastEnd = 0;
    for (auto &[s, e] : movies)
    {
        if (s >= lastEnd)
        {
            count++;
            lastEnd = e;
        }
    }
    cout << count << endl;
}
