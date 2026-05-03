#include <bits/stdc++.h>
using namespace std;

// 2915. Length of the Longest Subsequence That Sums to Target [M]
// LeetCode length-of-the-longest-subsequence-that-sums-to-target

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for(int num : nums) s += num;
        vector memo(n, vector<int>(target + 1, -1));

        auto dfs = [&] (this auto&&dfs, int i, int curSum) {
            if(curSum > target) return INT_MIN;
            if(i >= n) return curSum == target ? 0 : INT_MIN; 
            if(memo[i][curSum] != -1) return memo[i][curSum];
            return memo[i][curSum] = max(
                dfs(i + 1, curSum),
                dfs(i + 1, curSum + nums[i]) + 1
            );
        };
        int ans = dfs(0, 0);
        return ans <= 0 ? -1 : ans;
    }
};