// 79. Word Search [M]
// LeetCode word-search

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int len = word.size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        // vector memo(m, vector(n, vector(len, -1)));

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                auto dfs = [&] (this auto&& dfs, int i, int j, int idx) {
                    if(idx == len) return true;
                    if(i < 0 || j < 0 || i >= m || j >= n) return false;
                    if(board[i][j] == '#') return false;
                    char origin = board[i][j];
                    // if(memo[i][j][idx] != -1) return memo[i][j][idx] == 1;
                    // cout << board[i][j] << " " << word[idx] << endl;
                    bool ans = false;
                    if(word[idx] == board[i][j]) {
                        board[i][j] = '#';
                        for(auto& d : dirs) {
                            if(dfs(i + d.first, j + d.second, idx + 1)) {
                                ans = true;
                                break;
                            }
                        }
                    }
                    board[i][j] = origin;
                    // memo[i][j][idx] = (ans ? 1 : 0);
                    return ans;
                };
                if(dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};