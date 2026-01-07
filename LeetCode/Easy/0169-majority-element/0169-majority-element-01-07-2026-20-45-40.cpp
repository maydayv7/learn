class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, val;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                val = nums[i];
            } else if (val == nums[i])
                count++;
            else
                count--;
        }

        int check = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == val)
                check++;
        if (check > (n / 2))
            return val;
        else
            return -1;
    }
};
