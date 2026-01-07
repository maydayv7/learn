class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> val;
        for (int i = 0; i < nums.size(); i++)
            val.push_back({nums[i], i});
        sort(val.begin(), val.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = val[l].first + val[r].first;
            if (sum == target)
                break;
            else if (sum > target)
                r--;
            else
                l++;
        }
        return {val[l].second, val[r].second};
    }
};
