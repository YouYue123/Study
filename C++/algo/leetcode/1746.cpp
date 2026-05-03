#include <bits/stdc++.h>
using namespace std;

// 1746. Maximum Subarray Sum After One Operation [M]
// LeetCode maximum-subarray-sum-after-one-operation

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        // vector memo(
        //     n,
        //     vector(3, INT_MIN)
        // );
        int memo[n][3];
        std::fill(&memo[0][0], &memo[0][0] + n * 3, INT_MIN);        
        auto dfs = [&] (this auto&& dfs, int i, int state) {
            if(i == n) return state == 0 ? INT_MIN / 2 : 0;
            if(memo[i][state] != INT_MIN) return memo[i][state];
            int ans = 0;
            if(state == 0) {
                ans = max(
                    dfs(i + 1, 0),
                    dfs(i, 1)
                );
            } else if(state == 1) {
                ans = max(
                    nums[i] * nums[i] + dfs(i + 1, 2),
                    nums[i] + dfs(i + 1, 1)
                );
            } else if(state == 2) {
                ans = max(
                    ans,
                    nums[i] + dfs(i + 1, 2)
                );
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};