class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m % 2 == 01)
                m--;

            if (nums[m] == nums[m + 1])
                l = m + 2;
            else
                r = m;
        }
        return nums[l];
    }
};
