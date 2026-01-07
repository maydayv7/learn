#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, maxi = 0, neg = 1;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (cur < 0)
                cur = 0;
            else
                neg = 0;
            maxi = max(cur, maxi);
        }

        if (neg) {
            int maxe = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
                maxe = max(maxe, nums[i]);
            return maxe;
        }

        return maxi;
    }
};
