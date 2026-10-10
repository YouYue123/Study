#include <bits/stdc++.h>
using namespace std;

// 3693. Climbing Stairs II [M]
// LeetCode climbing-stairs-ii

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n + 1, -1);
        vector<int> dist = {1, 2, 3}; 
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            int ans = INT_MAX;
            if(memo[i] != -1) return memo[i];
            for(int d : dist) {
                int ni = i + d;
                if(ni <= n) ans = min(ans, dfs(ni) + costs[ni - 1] + d * d);
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};