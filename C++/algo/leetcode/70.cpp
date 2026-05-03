#include <bits/stdc++.h>
using namespace std;

// 70. Climbing Stairs [E]
// LeetCode climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(46, -1);
        auto dfs = [&] (this auto&& dfs, int n) {
            if(memo[n] != -1) return memo[n];
            if(n == 1) return 1;
            if(n == 2) return 2;
            return memo[n] = dfs(n - 1) + dfs(n - 2);
        };
        return dfs(n);
    }
};