#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Movie
{
    int start, end;
};

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<Movie> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].start >> movies[i].end;

    sort(movies.begin(), movies.end(), [](const Movie &a, const Movie &b)
         { if (a.end == b.end) return a.start < b.start; return a.end < b.end; });

    multiset<int> ends;
    for (int i = 0; i < k; i++)
        ends.insert(0);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // First member who's free after movie starts
        auto it = ends.upper_bound(movies[i].start);
        if (it == ends.begin())
            continue;
        --it;
        ans++;
        ends.erase(it);
        ends.insert(movies[i].end);
    }

    cout << ans << "\n";
    return 0;
}
