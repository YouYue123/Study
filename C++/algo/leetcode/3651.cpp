// 3651. Minimum Cost Path with Teleportations [H]
// LeetCode minimum-cost-path-with-teleportations

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int mx = 0;
        for (auto& r : grid) for (int x : r) mx = max(mx, x);

        // memo[t][i][j] 表示第 t 层到达 (i, j) 的最小代价
        vector memo(k + 1, vector(m, vector(n, -1)));
        // suf_min[t][val] 表示第 t 层中，格子值 >= val 的所有格子中的最小 dp 值
        vector suf_min(k + 1, vector(mx + 2, INF));

        auto dfs = [&](this auto&& dfs, int t, int i, int j) -> int {
            if (i < 0 || j < 0) return INF;
            if (memo[t][i][j] != -1) return memo[t][i][j];

            int res = INF;
            if (t == 0) {
                if (i == 0 && j == 0) res = 0; // 起点 (不计入 grid[0][0])
                else res = min(dfs(t, i - 1, j), dfs(t, i, j - 1)) + grid[i][j];
            } else {
                // 1. 从本层常规移动
                int move = min(dfs(t, i - 1, j), dfs(t, i, j - 1)) + grid[i][j];
                // 2. 从上一层的“跳跃”转移：利用已经计算好的后缀和
                int jump = suf_min[t - 1][grid[i][j]];
                res = min(move, jump);
            }
            return memo[t][i][j] = res;
        };

        // 必须按层级顺序触发，因为每一层需要填满 suf_min 给下一层用
        for (int t = 0; t <= k; ++t) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = dfs(t, i, j);
                    // 更新当前层对应 grid 值的最小值
                    suf_min[t][grid[i][j]] = min(suf_min[t][grid[i][j]], val);
                }
            }
            // 维护后缀最小值：suf_min[t][x] = min(dp[t][any_grid >= x])
            for (int x = mx; x >= 0; --x) {
                suf_min[t][x] = min(suf_min[t][x], suf_min[t][x + 1]);
            }
        }

        return memo[k][m - 1][n - 1];
    }
};