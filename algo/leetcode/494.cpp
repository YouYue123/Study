#include <bits/stdc++.h>
using namespace std;

// 494. Target Sum [M]
// LeetCode target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for(int num: nums) s += num;
        vector memo(n, 
            vector(
                2001, 
                -1 
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int curSum) -> int {
            if(i >= n) return curSum * 2 == target + s ? 1 : 0;
            if(memo[i][curSum + 1000] != -1) return memo[i][curSum + 1000];
            return memo[i][curSum + 1000] = dfs(i + 1, curSum) + dfs(i + 1, curSum + nums[i]);
        };
        return dfs(0, 0);
    }
};