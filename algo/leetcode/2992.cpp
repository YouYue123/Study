#include <bits/stdc++.h>
using namespace std;

// 2992. Number of Self-Divisible Permutations [M]
// LeetCode number-of-self-divisible-permutations

class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        int full = (1 << n) - 1;
        vector memo(1 << n, -1);
        auto dfs = [&] (this auto&& dfs, int state) {
            if(full == state) return 1;
            if(memo[state] != -1) return memo[state];
            int cnt = __builtin_popcount(state) + 1;
            int ans = 0;
            for(int i = 0; i < n; i ++) {
                if(state & (1 << i)) continue;
                if(gcd(i + 1, cnt) == 1) {
                    ans += dfs(state | (1 << i));
                }
            }
            return memo[state] = ans;
        };
        return dfs(0);
    }
};