#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev = {1};
        for (int n=0; n<numRows; n++) {
            vector<int> cur;
            cur.push_back(1);
            if (n!=0) {
                for (int i=0; i<prev.size()-1; i++) {
                    cur.push_back(prev[i]+prev[i+1]);
                }
                cur.push_back(1);
            }
            res.push_back(cur);
            prev = cur;
        }
        return res;
    }
};
