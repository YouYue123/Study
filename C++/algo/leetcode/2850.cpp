// 2850. Minimum Moves to Spread Stones Over Grid [M]
// LeetCode minimum-moves-to-spread-stones-over-grid

int INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> from, to;
        for (int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[i].size(); j ++) {
                if(grid[i][j]) {
                    for(int k = 1; k < grid[i][j]; k ++) {
                        from.emplace_back(i, j);
                    }
                } else {
                    to.emplace_back(i, j);
                }
            }
        }
        int m = from.size();
        vector<int> memo(1 << m, -1);
        auto dfs = [&](this auto&& dfs, int i, int state) {
            if (i == m) return 0;
            if (memo[state] != -1) return memo[state];
            int res = INF;
            for (int j = 0; j < m; ++j) {
                if(state & (1 << j)) continue;
                int dist = abs(from[i].first - to[j].first) + abs(from[i].second - to[j].second);
                res = min(res, dist + dfs(i + 1, state | (1 << j)));
            }
            return memo[state] = res;
        };
        return dfs(0, 0);
    }
};