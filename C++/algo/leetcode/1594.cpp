// 1594. Maximum Non Negative Product in a Matrix [M]
// LeetCode maximum-non-negative-product-in-a-matrix

int constexpr INF = 0x3f3f3f3f;
int MOD = 1e9 + 7;
using pll = pair<long long, long long>;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}
        };
        vector memo(m, vector<pll>(n, { -INF, -INF }));
        // {min, max}
        auto dfs = [&](this auto&& dfs, int i, int j) -> pll {
            pll ans = { INF, -INF };
            if(i == m - 1 && j == n -1) return { grid[i][j], grid[i][j] };
            if(memo[i][j].first != -INF) return memo[i][j];
            for(auto& dir : dirs) {
                int nxt_i = i + dir.first, nxt_j = j + dir.second;
                if(nxt_i >= m || nxt_j >= n) continue;
                auto val = dfs(nxt_i, nxt_j);
                ans.first = min({
                    ans.first,
                    val.first * grid[i][j], 
                    val.second * grid[i][j]
                });
                ans.second = max({
                    ans.second,
                    val.first * grid[i][j], 
                    val.second * grid[i][j]
                });
            }
            return memo[i][j] = ans;
        };
        auto ans = dfs(0, 0);
        return ans.second < 0 ? -1 : ans.second % MOD;
    }
};