class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> val(n);
        for (int i = 0; i < n; ++i)
            val[i] = {nums[i], i};

        vector<int> count(n, 0);
        mergeSort(val, 0, n - 1, count);
        return count;
    }

private:
    void mergeSort(vector<pair<int, int>>& val, int l, int r,
                   vector<int>& count) {
        if (l >= r)
            return;
        int mid = (r + l) / 2;
        mergeSort(val, l, mid, count);
        mergeSort(val, mid + 1, r, count);
        merge(val, l, mid, r, count);
    }

    void merge(vector<pair<int, int>>& val, int l, int mid, int r,
               vector<int>& count) {
        vector<pair<int, int>> temp;
        int i = l;
        int j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= r) {
            if (val[j].first < val[i].first) {
                smaller++;
                temp.push_back(val[j++]);
            } else {
                count[val[i].second] += smaller;
                temp.push_back(val[i++]);
            }
        }

        while (i <= mid) {
            count[val[i].second] += smaller;
            temp.push_back(val[i++]);
        }

        while (j <= r)
            temp.push_back(val[j++]);

        for (int k = 0; k < temp.size(); ++k)
            val[l + k] = temp[k];
    }
};
