class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int s = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (m.find(s - k) != m.end())
                count += m[s - k];
            m[s]++;
        }
        return count;
    }
};
