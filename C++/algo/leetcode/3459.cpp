// 3459. Length of Longest V-Shaped Diagonal Segment [H]
// LeetCode length-of-longest-v-shaped-diagonal-segment

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            { 1, 1 }, { -1 , 1 }, { -1, -1 }, { 1, - 1 }
        };
        vector memo(
            m, 
            vector<array<array<int, 2>, 4>>(n)
        );

        auto dfs = [&] (this auto&& dfs, int i, int j, int k, bool canTurn, int target) {
            i += dirs[k].first;
            j += dirs[k].second;
            if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] != target) return 0;
            if(memo[i][j][k][canTurn] != 0) return memo[i][j][k][canTurn];
            int ans = dfs(i, j, k, canTurn, 2 - target) + 1;
            if(canTurn) ans = max(ans, dfs(i, j, (k + 3) % 4, false, 2 - target) + 1);
            return memo[i][j][k][canTurn] = ans;
        };
        int ans = 0 ;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d <= 3; d ++) ans = max(ans, dfs(i, j, d, true, 2) + 1);
                }
            }
        }
        return ans;
    }
};