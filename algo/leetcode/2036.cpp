#include <bits/stdc++.h>
using namespace std;

// 2036. Maximum Alternating Subarray Sum [M]
// LeetCode maximum-alternating-subarray-sum

class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, vector(3, LLONG_MIN));
        auto dfs = [&](this auto&& dfs, int i, int state) -> long long{
            if(i == n) return state == 0 ? LLONG_MIN / 2 : 0LL;
            if(memo[i][state] != LLONG_MIN) return memo[i][state];
            long long ans = 0;
            if(state == 0) {
                ans = max(
                    dfs(i + 1, 0),
                    nums[i] + dfs(i + 1, 1)
                );
            } else if(state == 1) {
                ans = max(
                    0LL,
                    -nums[i] + dfs(i + 1, 2)
                );
            } else if(state == 2) {
                ans = max(
                    0LL,
                    nums[i] + dfs(i + 1, 1)
                );
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};