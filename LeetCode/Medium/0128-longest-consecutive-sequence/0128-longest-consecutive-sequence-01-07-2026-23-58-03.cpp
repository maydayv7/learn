class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int len = 1;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(nums[i]);

        for (auto it : s) {
            if (s.find(it - 1) == s.end()) {
                int l = 1;
                int x = it;
                while (s.find(x + 1) != s.end()) {
                    x += 1;
                    l += 1;
                }
                len = max(len, l);
            }
        }
        return len;
    }
};
