#include <bits/stdc++.h>
using namespace std;

// 163. Missing Ranges [E]
// LeetCode missing-ranges

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int curLow = lower;
        for (int num: nums) {
            if (num < lower) continue;
            if (num > upper) break;
            if(curLow == num) {
                curLow += 1;
            } else if(curLow < num) {
                ans.push_back({ curLow, num - 1 });
                curLow = num + 1;
            }
        }
        if (curLow <= upper) {
            ans.push_back({ curLow, upper });
        }
        return ans;
    }
};