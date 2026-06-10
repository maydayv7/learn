#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, t;
    cin >> n >> t;

    vector<int> k(n);
    int mint = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        mint = min(mint, k[i]);
    }

    int low = 1;
    int high = mint * t;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int products = 0;

        for (int i = 0; i < n; i++)
        {
            products += (mid / k[i]);
            if (products >= t)
                break;
        }

        if (products >= t)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}
