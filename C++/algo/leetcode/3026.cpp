#include <bits/stdc++.h>
using namespace std;

// 3026. Maximum Good Subarray Sum [M]
// LeetCode maximum-good-subarray-sum

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long ans = LLONG_MIN;
        unordered_map<int, long long> dict;
        for(int num : nums) dict[num] = LLONG_MAX;
        for(int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            int r1 = nums[i] + k;
            int r2 = nums[i] - k;
            if(dict.contains(r1) && dict[r1] != LLONG_MAX) {
                ans = max(ans, sum - dict[r1]);
            }
            if(dict.contains(r2) && dict[r2] != LLONG_MAX ) {
                ans = max(ans, sum - dict[r2]);
            }
            dict[nums[i]] = min(dict[nums[i]], sum - nums[i]);
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};