/* Find median in row-wise sorted matrix */

#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, matrix[i][m - 1]);
        mini = min(mini, matrix[i][0]);
    }

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

        if (count < (n * m + 1) / 2)
            mini = mid + 1;
        else
            maxi = mid;
    }

    return mini;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    cout << "Median is " << findMedian(matrix) << endl;
    return 0;
}
