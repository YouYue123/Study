#include <bits/stdc++.h>
using namespace std;

// 746. Min Cost Climbing Stairs [E]
// LeetCode min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        auto dfs = [&](this auto&& dfs, int i) {
            if(i >= cost.size()) return 0;
            if(memo[i] != -1) return memo[i];
            return memo[i] = min(dfs(i + 1), dfs(i + 2)) + cost[i];
        };
        return min(dfs(0), dfs(1));
    }
};