class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long s = grid.size();
        long long n = s * s;
        long long S1 = (n * (n + 1)) / 2;
        long long S2 = (n * (n + 1) * (2 * n + 1)) / 6;

        long long s1 = 0, s2 = 0;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                long long val = grid[i][j];
                s1 += val;
                s2 += val * val;
            }
        }

        long long diff = S1 - s1;
        long long sq_diff = S2 - s2;
        long long sum = sq_diff / diff;

        long long missing = (diff + sum) / 2;
        long long repeating = sum - missing;

        return {(int)repeating, (int)missing};
    }
};
