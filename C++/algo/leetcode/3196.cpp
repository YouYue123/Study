#include <bits/stdc++.h>
using namespace std;

// 3196. Maximize Total Cost of Alternating Subarrays [M]
// LeetCode maximize-total-cost-of-alternating-subarrays

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector memo(
            n, 
            vector(2, -1LL)
        );
        auto dfs = [&] (this auto&& dfs, int i, int state) -> long long{
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            long long ans = 0;
            if(state == 0) {
                ans = max(
                    dfs(i + 1, 1) + nums[i],
                    dfs(i + 1, 0) + nums[i]
                );
            } else {
                ans = dfs(i + 1, 0) - nums[i];
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};