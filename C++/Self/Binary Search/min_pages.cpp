/* Allocate books in contiguous manner such that the maximum number of pages assigned to a student is minimum */

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
            pagesStudent += arr[i];
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n)
{
    if (n > arr.size())
        return -1;

    int low = INT_MIN, high = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        low = max(low, arr[i]);
        high += arr[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > n)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 4;

    cout << "Maximum number of pages allocated: " << findPages(arr, n) << "\n";
    return 0;
}
