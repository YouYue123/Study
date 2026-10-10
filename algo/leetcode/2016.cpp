#include <bits/stdc++.h>
using namespace std;

// 2016. Maximum Difference Between Increasing Elements [E]
// LeetCode maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curMin = nums[0];
        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] > curMin) {
                ans = max(ans, nums[i] - curMin);
            }
            curMin = min(curMin, nums[i]);
        }
        return ans == INT_MIN ? -1 : ans;
    }
};