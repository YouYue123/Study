// 51. N-Queens [H]
// LeetCode n-queens

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        auto dfs = [&] (this auto&& dfs, vector<string>& tmp) {
            if(tmp.size() == n) {
                ans.push_back(tmp);
                return;
            }
            string cur = string(n, '.');
            int row = tmp.size();
            for(int col = 0; col < n; col ++) {
                bool is_valid = true;
                for(int prev_row = 0; prev_row < tmp.size(); prev_row ++) {
                    if(tmp[prev_row][col] == 'Q') {
                        is_valid = false;
                        break;
                    }
                    int left_diag_idx = col - (row - prev_row);
                    int right_diag_idx = col + (row - prev_row);
                    if(left_diag_idx >= 0 && tmp[prev_row][left_diag_idx] == 'Q') {
                        is_valid = false;
                        break;
                    }
                    if(right_diag_idx < n && tmp[prev_row][right_diag_idx] == 'Q') {
                        is_valid = false;
                        break;
                    }
                }
                if(!is_valid) continue;
                cur[col] = 'Q';
                tmp.push_back(cur);
                dfs(tmp);
                tmp.pop_back();
                cur[col] = '.';
            }
        };
        vector<string> tmp;
        dfs(tmp);
        return ans;
    }
};