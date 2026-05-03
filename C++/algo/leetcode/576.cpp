// 576. Out of Boundary Paths [M]
// LeetCode out-of-boundary-paths

int MOD = 1e9 + 7;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        vector memo(m, vector(n, vector(maxMove + 1, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int j, int curMove) {
            if(curMove > maxMove) return 0;
            if(i >= m || j >= n || i < 0 || j < 0) return 1;
            if(memo[i][j][curMove] != -1) return memo[i][j][curMove];
            int ans = 0;
            for(auto& d : dirs) {
                ans = (ans + dfs(i + d.first, j + d.second, curMove + 1)) % MOD;
            }
            return memo[i][j][curMove] = ans;
        };

        return dfs(startRow, startColumn, 0);
    }
};