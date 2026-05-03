// 3148. Maximum Difference Score in a Grid [M]
// LeetCode maximum-difference-score-in-a-grid

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector(n, INF));
        auto dfs = [&] (this auto&& dfs, int i, int j) -> int {
            if(memo[i][j] != INF) return memo[i][j];
            int ans = -INF;
            if(i + 1 < m) {
                int score = grid[i + 1][j] - grid[i][j];
                ans = max(
                    score,
                    score + dfs(i + 1, j)
                );
            }
            if(j + 1 < n) {
                int score = grid[i][j + 1] - grid[i][j];
                ans = max({
                    ans,
                    score,
                    score + dfs(i, j + 1),
                });
            }
            return memo[i][j] = ans;
        };
        int ans = -INF;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};