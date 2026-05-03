#include <bits/stdc++.h>
using namespace std;

// 2708. Maximum Strength of a Group [M]
// LeetCode maximum-strength-of-a-group

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long curMax = nums[0], curMin = nums[0];
        for(int i = 1; i < n; i ++) {
            long long prevMax = curMax;
            curMax = max({
                prevMax,
                (long long)nums[i],
                curMin * nums[i],
                prevMax * nums[i]
            });
            curMin = min({
                curMin,
                (long long) nums[i],
                curMin * nums[i],
                prevMax * nums[i]
            });
        }
        return curMax;
    }
};