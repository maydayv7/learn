#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6;

// Ways to build a tower of height i where the top floor has 2 separate 1x1 blocks
int dp_sep[MAX_N + 1];

// Ways to build tower of height i where top floor has 1 fused 2x1 block
int dp_fused[MAX_N + 1];

void precompute()
{
    dp_sep[1] = 1;
    dp_fused[1] = 1;
    for (int i = 2; i <= MAX_N; i++)
    {
        // From a separate top, we can form:
        // - 4 separate variations (extend left, extend right, extend both, start 2 new 1x1s)
        // - 1 fused variation (start a new 2x1)
        // From a fused top, we can form:
        // - 2 fused variations (extend the 2x1, start a new 2x1)
        // - 1 separate variation (start 2 new 1x1s)
        dp_sep[i] = (4 * dp_sep[i - 1] + dp_fused[i - 1]) % MOD;
        dp_fused[i] = (dp_sep[i - 1] + 2 * dp_fused[i - 1]) % MOD;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int total_ways = (dp_sep[n] + dp_fused[n]) % MOD;
        cout << total_ways << "\n";
    }

    return 0;
}
