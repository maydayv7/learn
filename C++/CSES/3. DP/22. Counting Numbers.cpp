#include <bits/stdc++.h>
#define int long long
using namespace std;

// dp[index][last_digit + 1][is_tight][is_leading_zero]
// max digits for 10^18 is ~19. last_digit -> -1 to 9.
int dp[20][12][2][2];

int calc(const string &s, int idx, int last_digit, bool is_tight, bool is_leading_zero)
{
    if (idx == s.length())
        return 1;

    // last_digit + 1 used to shift index range, [-1, 9] -> [0, 10] (no negative indices)
    if (dp[idx][last_digit + 1][is_tight][is_leading_zero] != -1)
        return dp[idx][last_digit + 1][is_tight][is_leading_zero];

    int ans = 0;
    int limit = is_tight ? (s[idx] - '0') : 9; // Upper bound for current digit
    for (int digit = 0; digit <= limit; ++digit)
    {
        bool next_tight = is_tight && (digit == limit);
        bool next_leading_zero = is_leading_zero && (digit == 0);

        if (next_leading_zero)
            ans += calc(s, idx + 1, -1, next_tight, true);
        else if (digit != last_digit)
            ans += calc(s, idx + 1, digit, next_tight, false);
    }

    return dp[idx][last_digit + 1][is_tight][is_leading_zero] = ans;
}

int solve(int x)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1;

    string s = to_string(x);
    memset(dp, -1, sizeof(dp));

    return calc(s, 0, -1, true, true);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << "\n";

    return 0;
}
