class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if (l >= r)
            return cnt;
        int m = (l + r) / 2;
        cnt += mergeSort(arr, l, m);
        cnt += mergeSort(arr, m + 1, r);
        cnt += countPairs(arr, l, m, r);
        merge(arr, l, m, r);
        return cnt;
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int n1 = l;
        int n2 = m + 1;
        while (n1 <= m && n2 <= r) {
            if (arr[n1] <= arr[n2])
                temp.push_back(arr[n1++]);
            else
                temp.push_back(arr[n2++]);
        }

        while (n1 <= m)
            temp.push_back(arr[n1++]);

        while (n2 <= r)
            temp.push_back(arr[n2++]);

        for (int i = l; i <= r; i++)
            arr[i] = temp[i - l];
    }

    int countPairs(vector<int>& arr, int l, int m, int r) {
        int n2 = m + 1;
        int cnt = 0;
        for (int i = l; i <= m; i++) {
            while (n2 <= r && arr[i] > 2L * arr[n2])
                n2++;
            cnt += (n2 - (m + 1));
        }
        return cnt;
    }
};
