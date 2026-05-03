#include <bits/stdc++.h>
using namespace std;

// 983. Minimum Cost For Tickets [M]
// LeetCode minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set set(days.begin(), days.end());
        vector<int> memo(days[n - 1] + 1, -1);
        auto dfs = [&](this auto&& dfs, int d) {
            if(d < 0) return 0;
            if(memo[d] != -1) return memo[d];
            int ans = 0;
            if(!set.contains(d)) {
                ans = dfs(d - 1);
            } else {
                ans = min({
                    costs[0] + dfs(d - 1),
                    costs[1] + dfs(d - 7),
                    costs[2] + dfs(d - 30)
                });
            }
            return memo[d] = ans;
        };
        return dfs(days[n - 1]);
    }
};