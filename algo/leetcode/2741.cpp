#include <bits/stdc++.h>
using namespace std;

// 2741. Special Permutations [M]
// LeetCode special-permutations

int MOD = 1e9 + 7;
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        int full = (1 << n) - 1;
        vector<unordered_map<int, int>> memo(1 << n);
        auto dfs = [&] (this auto&& dfs, int state, int prev) {
            if(full == state) return 1;
            if(memo[state].contains(prev)) return memo[state][prev];
            int ans = 0;
            for(int k = 0; k < n; k ++) {
                if(state & (1 << k)) continue;
                if(prev == 0 || prev % nums[k] == 0 || nums[k] % prev == 0) {
                    ans = (ans + dfs(state | (1 << k), nums[k])) % MOD;
                }
            }
            return memo[state][prev] = ans;
        };
        return dfs(0, 0);
    }
};