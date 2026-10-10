#include <bits/stdc++.h>
using namespace std;

// 3584. Maximum Product of First and Last Elements of a Subsequence [M]
// LeetCode maximum-product-of-first-and-last-elements-of-a-subsequence

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        if(m == 1) {
            for(int num : nums) {
                ans = max(ans, (long long) num * num);
            }
            return ans;
        }
        vector<int> minPresum(n);
        vector<int> maxPresum(n);
        minPresum[0] = nums[0];
        maxPresum[0] = nums[0];
        for(int i = 1; i < n; i ++) {
            minPresum[i] = min(minPresum[i - 1], nums[i]);
            maxPresum[i] = max(maxPresum[i - 1], nums[i]);
        }
        for(int i = m - 1; i < n; i ++) {
            int j = i - (m - 1);
            long long preMin = minPresum[j];
            long long preMax = maxPresum[j];
            ans = max({
                ans,
                preMin * nums[i],
                preMax * nums[i]
            });
        }
        return ans;
    }
};