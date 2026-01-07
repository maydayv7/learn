class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int i = (r + l) / 2;
            int val = matrix[i / n][i % n];
            if (val == target)
                return true;
            else if (val > target)
                r = i - 1;
            else
                l = i + 1;
        }
        return false;
    }
};
