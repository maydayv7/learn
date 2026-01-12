class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            while (pq.top().second <= i - k)
                pq.pop();

            if (i >= k - 1)
                res.push_back(pq.top().first);
        }

        return res;
    }
};
