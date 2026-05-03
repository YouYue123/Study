#include <bits/stdc++.h>
using namespace std;

// 1039. Minimum Score Triangulation of Polygon [M]
// LeetCode minimum-score-triangulation-of-polygon

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i + 1 == j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INF;
            for(int k = i + 1; k < j; k ++) {
                ans = min(
                    ans,
                    dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]
                );
            }
            return memo[i][j] = ans;
        };
        
        return dfs(0, n - 1);
    }
};