// 417. Pacific Atlantic Water Flow [M]
// LeetCode pacific-atlantic-water-flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, -1}, {0, 1}
        };
        vector<vector<bool>> mark1(m, vector<bool>(n, false));
        vector<vector<bool>> mark2(m, vector<bool>(n, false));

        auto dfs = [&] (this auto&& dfs, int i, int j, vector<vector<bool>>& visited) -> void {
            visited[i][j] = true;
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if(heights[ni][nj] < heights[i][j]) continue;
                if(visited[ni][nj]) continue;
                dfs(ni, nj, visited);
            }
        };
        for(int i = 0; i < m; i ++) {
            dfs(i, 0, mark1);
            dfs(i, n - 1, mark2);
        }
        for(int j = 0; j < n; j ++) {
            dfs(0, j, mark1);
            dfs(m - 1, j, mark2);
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                // cout << i << " " << j << endl;
                // cout << mark1[i][j] << " " << mark2[i][j] << endl;
                // cout << "=========" << endl;
                if(mark1[i][j] && mark2[i][j]) {
                    ans.push_back({ i, j });
                }
            }
        }
        return ans;
    }
};