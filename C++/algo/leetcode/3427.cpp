#include <bits/stdc++.h>
using namespace std;

// 3427. Sum of Variable Length Subarrays [E]
// LeetCode sum-of-variable-length-subarrays

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> preSum(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i ++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            ans += preSum[i + 1] - preSum[max(0, i - nums[i])];
        }
        return ans;
    }
};