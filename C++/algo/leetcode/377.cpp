#include <bits/stdc++.h>
using namespace std;

// 377. Combination Sum IV [M]
// LeetCode combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        auto dfs = [&] (this auto&& dfs, int t) {
            if(t == 0) return 1;
            if(t < 0) return -1;
            if(memo[t] != -1) return memo[t];
            int ans = 0;
            for(int num : nums) {
                int c = dfs(t - num);
                if(c != -1) ans += c;
            }
            return memo[t] = ans;
        };
        return dfs(target);
    }
};