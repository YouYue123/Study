#include <bits/stdc++.h>
using namespace std;

// 198. House Robber [M]
// LeetCode house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i >= n) return 0;
            if(memo[i] != -1) return memo[i];
            return memo[i] = max(
                nums[i] + dfs(i + 2),
                dfs(i + 1)
            );
        };
        return dfs(0);
    }
};