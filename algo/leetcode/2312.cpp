#include <bits/stdc++.h>
using namespace std;

// 2312. Selling Pieces of Wood [H]
// LeetCode selling-pieces-of-wood

using pii = pair<int, int>;
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pii, int> dict;
        for(auto& p : prices) {
            dict[{p[0], p[1]}] = p[2];
        }
        long long memo[m + 1][n + 1];
        memset(memo, -1LL, sizeof(memo));
        // vector memo(m + 1, vector(n + 1, -1LL));
        auto dfs = [&] (this auto&& dfs, int h, int w) -> long long {
            // cout << h << " " << w << endl;
            if(memo[h][w] != -1) return memo[h][w];
            long long ans = 0;
            if(dict.contains({h, w})) ans = dict[{h, w}];
            for(int nxtH = 1; nxtH <= h / 2; nxtH ++) {
                ans = max(ans, dfs(nxtH, w) + dfs(h - nxtH, w));
            }
            for(int nxtW = 1; nxtW <= w / 2; nxtW ++) {
                ans = max(ans, dfs(h, nxtW) + dfs(h, w - nxtW));
            }
            return memo[h][w] = ans;
        };

        return dfs(m, n);
    }
};