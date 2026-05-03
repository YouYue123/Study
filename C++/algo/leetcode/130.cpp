// 130. Surrounded Regions [M]
// LeetCode surrounded-regions

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> dirs= {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int m = board.size(), n = board[0].size();
        auto dfs = [&] (this auto&& dfs, int i, int j) -> void {
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || ni >= m || nj < 0 || nj >= n)  continue;
                if(board[ni][nj] != 'O') continue;
                board[ni][nj] = 'M';
                dfs(ni, nj);
            }
        };
        for(int i = 0; i < m; i ++) {
            dfs(i, -1);
            dfs(i, n);
        }
        for(int j = 0; j < n; j ++) {
            dfs(-1, j);
            dfs(m, j);
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'M') board[i][j] = 'O';
            }
        }
    }
};