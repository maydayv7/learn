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
        ind++;
        while (ind < nums.size() && nums[ind] == nums[ind - 1])
            ind++;
        subsetGen(ind, nums, cur, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        subsetGen(0, nums, cur, res);
        return res;
    }
};
