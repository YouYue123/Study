#include <bits/stdc++.h>
using namespace std;

// 3355. Zero Array Transformation I [M]
// LeetCode zero-array-transformation-i

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1, 0);
        diff[0] = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            diff[i] = nums[i] - nums[i - 1];
        }
        for(vector<int>& q : queries) {
            diff[q[0]] -= 1;
            diff[q[1] + 1] += 1;
        }
        int cur = 0;
        for(int i = 0; i < nums.size(); i ++) {
            cur += diff[i];
            if(cur > 0) return false;
        }
        return true;
    }
};