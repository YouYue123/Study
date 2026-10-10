#include <bits/stdc++.h>
using namespace std;

// 1578. Minimum Time to Make Rope Colorful [M]
// LeetCode minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        unordered_map<long long, int> memo;
        auto dfs = [&] (this auto &&dfs, int cur, char preC) {
            int ans = 0;
            long long key = ((long long)cur << 32) | preC;
            if(memo.contains(key)) return memo[key];
            if(cur == colors.size()) return ans;
            if(colors[cur] == preC) {
                ans = neededTime[cur] + dfs(cur + 1, preC);
            } else {
                ans = min(
                    dfs(cur + 1, colors[cur]),
                    neededTime[cur] + dfs(cur + 1, preC)
                );
            }
            return memo[key] = ans;
        };
        return dfs(0, '*');
    }
};