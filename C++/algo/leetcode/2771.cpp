#include <bits/stdc++.h>
using namespace std;

// 2771. Longest Non-decreasing Subarray From Two Arrays [M]
// LeetCode longest-non-decreasing-subarray-from-two-arrays

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector memo(
            n, 
            vector(3, -1)
        );
        // state 0: not selected
        // state 1: prev selected nums1
        // state 2: prev selected nums2
        auto dfs = [&] (this auto&& dfs, int i, int state) {
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            int ans = 0;
            if(state == 0) {
                ans = max(ans, dfs(i + 1, 1) + 1);
                ans = max(ans, dfs(i + 1, 2) + 1);
                ans = max(ans, dfs(i + 1, 0));
            } else {
                int preVal = (state == 1) ? nums1[i - 1] : nums2[i - 1];
                if(nums1[i] >= preVal) ans = max(ans, dfs(i + 1, 1) + 1);
                if(nums2[i] >= preVal) ans = max(ans, dfs(i + 1, 2) + 1);
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};