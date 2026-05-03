#include <bits/stdc++.h>
using namespace std;

// 3381. Maximum Subarray Sum With Length Divisible by K [M]
// LeetCode maximum-subarray-sum-with-length-divisible-by-k

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = nums[i] + presum[i];
        long long ans = LONG_MIN;
        for(int i = 0; i < k; i ++) {
            long long cur = 0;
            for(int j = i; j < n - k + 1; j += k) {
                long long sum = presum[j + k] - presum[j];
                // cout << "start: " << j << " end: " << j + k - 1 << " sum: " << sum << endl;
                cur = max(cur + sum, sum);
                ans = max(ans, cur);
            }
            // cout << endl;
        }
        return ans;
    }
};