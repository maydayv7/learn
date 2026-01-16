class Solution {
public:
    void subsetGen(int ind, vector<int>& nums, vector<int>& cur,
                   vector<vector<int>>& res) {
        if (ind == nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[ind]);
        subsetGen(ind + 1, nums, cur, res);

        cur.pop_back();
        subsetGen(ind + 1, nums, cur, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        subsetGen(0, nums, cur, res);
        return res;
    }
};
