#include <bits/stdc++.h>
using namespace std;

// 3068. Find the Maximum Sum of Node Values [H]
// LeetCode find-the-maximum-sum-of-node-values

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector memo(n, vector(2, -1LL));
        auto dfs = [&] (this auto&& dfs, int i, int state) -> long long {
            if(i == n) return state == 0 ? 0 : LLONG_MIN / 2;
            if(memo[i][state] != -1LL) return memo[i][state];
            long long ans = max(
                nums[i] + dfs(i + 1, state),
                (nums[i] ^ k) + dfs(i + 1, state ^ 1)
            );
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};