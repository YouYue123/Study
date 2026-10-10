#include <bits/stdc++.h>
using namespace std;

// 3429. Paint House IV [M]
// LeetCode paint-house-iv

long long constexpr INF = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector memo(n, vector(4, vector(4, -1LL)));
        auto dfs = [&] (this auto&& dfs, int i, int colorA, int colorB) { 
            if(i == n) return 0LL;
            if(memo[i][colorA][colorB] != -1LL) return memo[i][colorA][colorB];
            long long ans = INF;
            for(int a = 0; a < 3; a ++) {
                for(int b = 0; b < 3; b ++) {
                    if(a == colorA || b == colorB || a == b) continue;
                    ans = min(
                        ans,
                        dfs(i + 1, a, b) +  cost[i][a] + cost[n - i - 1][b]
                    );
                }
            }
            return memo[i][colorA][colorB] = ans;
        };

        return dfs(n / 2, 3, 3);
    }
};