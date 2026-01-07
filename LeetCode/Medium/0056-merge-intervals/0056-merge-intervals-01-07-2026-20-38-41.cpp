class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> prev = intervals[0];
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> cur = intervals[i];
            if (cur[0] <= prev[1])
                prev[1] = max(prev[1], cur[1]);
            else {
                res.push_back(prev);
                prev = cur;
            }
        }
        res.push_back(prev);
        return res;
    }
};
