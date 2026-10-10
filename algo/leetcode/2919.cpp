#include <bits/stdc++.h>
using namespace std;

// 2919. Minimum Increment Operations to Make Array Beautiful [M]
// LeetCode minimum-increment-operations-to-make-array-beautiful

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(
            n,
            vector(3, -1LL)
        );
        auto dfs = [&] (this auto&& dfs, int i, int state) -> long long {
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            long long ans = LLONG_MAX;
            if(state == 0 || state == 1) {
                ans = min(
                    dfs(i + 1, 0) + max(k - nums[i], 0),
                    dfs(i + 1, state + 1)
                );
            } else if(state == 2) {
                ans =  dfs(i + 1, 0) + max(k - nums[i], 0);
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};