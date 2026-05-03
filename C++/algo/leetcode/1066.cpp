#include <bits/stdc++.h>
using namespace std;

// 1066. Campus Bikes II [M]
// LeetCode campus-bikes-ii

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        int full = (1 << n) - 1;
        vector memo(1 << n, vector(1 << m, -1));
        auto dfs = [&] (this auto&& dfs, int wState, int bState) {
            if(full == wState) return 0;
            if(memo[wState][bState] != -1) return memo[wState][bState];
            int ans = INF;
            for(int i = 0; i < n; i ++) {
                if(wState & (1 << i)) continue;
                for(int j = 0; j < m; j ++) {
                    if(bState & (1 << j)) continue;
                    int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]); 
                    ans = min(
                        ans,
                        dfs(wState | (1 << i), bState | (1 << j)) + dist
                    );
                }
            }
            return memo[wState][bState] = ans;
        };

        return dfs(0, 0);
    }
};