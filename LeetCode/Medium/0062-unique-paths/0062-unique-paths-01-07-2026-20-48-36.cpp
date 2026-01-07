class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m + n - 2 >= 2)
            return nCr(m + n - 2, min(m - 1, n - 1));
        else
            return 1;
    }

private:
    int nCr(int n, int r) {
        double sum = 1;
        for (int i = 1; i <= r; i++)
            sum = sum * (n - r + i) / i;
        return (int)sum;
    }
};
