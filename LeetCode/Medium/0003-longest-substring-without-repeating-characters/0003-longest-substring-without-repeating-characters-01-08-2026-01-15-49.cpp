class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256];
        for (int i = 0; i < 256; ++i)
            arr[i] = -1;

        int l = 0, r = 0, maxl = 0;
        while (r < s.size()) {
            if (arr[s[r]] != -1)
                l = max(arr[s[r]] + 1, l);

            maxl = max(r - l + 1, maxl);
            arr[s[r]] = r;
            r++;
        }
        return maxl;
    }
};
