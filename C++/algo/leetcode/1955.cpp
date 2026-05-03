#include <bits/stdc++.h>
using namespace std;

// 1955. Count Number of Special Subsequences [H]
// LeetCode count-number-of-special-subsequences

int MOD = 1e9 + 7;
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long memo[n][4];
        memset(memo, -1LL, sizeof(memo));
        auto dfs = [&](this auto&& dfs, int i, int state) -> long long {
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            long long ans = dfs(i + 1, state); // skip
            if(state == 0 || state == 3) {
                if(nums[i] == 0) {
                    ans = (ans + dfs(i + 1, 0)) % MOD; // select 0
                }  
                if(nums[i] == 1 && state == 0) {
                    ans = (ans + dfs(i + 1, 1)) % MOD; // select 1
                }
            } else if(state == 1) {
                if(nums[i] == 1) {
                    ans = (ans + dfs(i + 1, 1)) % MOD; // select 1
                } else if(nums[i] == 2) {
                    ans = (ans + 1 + dfs(i + 1, 2)) % MOD; // select 2
                }
            } else if(state == 2) {
                if(nums[i] == 2) {
                    ans = (ans + 1 + dfs(i + 1, 2)) % MOD; // select 2
                }
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 3);
    }
};