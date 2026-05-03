// 1301. Number of Paths with Max Score [H]
// LeetCode number-of-paths-with-max-score

int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size();
        using pii = pair<long long, long long>;
        if(board[m - 1][n - 1] == 'X' || board[0][0] == 'X') return {0, 0};
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {1, 1}
        };
        vector<vector<pii>> memo(m, vector<pii>(n, { -1, -1 }));
        auto dfs = [&] (this auto&& dfs, int i, int j) -> pii {
            if(i == m - 1 && j == n - 1) return { 0, 1 };
            if(i >= m || j >= n || board[i][j] == 'X') return { INT_MIN, 0 };
            if(memo[i][j].first != -1) {
                // cout << "cache hit" << endl;
                return memo[i][j];
            }
            pii ans = { INT_MIN, 0 };
            for(auto& d : dirs) {
                pii nx = dfs(i + d.first, j + d.second);
                if(nx.first != INT_MIN ) {
                    if(ans.first == nx.first) {
                        ans.second = (ans.second + nx.second) %MOD;
                    } else if (ans.first < nx.first) {
                        ans.first = nx.first;
                        ans.second = nx.second;
                    }
                }
            }
            if(ans.first == INT_MIN) return memo[i][j] = ans;
            if(board[i][j] != 'E') ans.first += (board[i][j] - '0');
            return memo[i][j] = ans;
        };
        auto ans = dfs(0, 0);
        // for(int i = 0; i < m ; i ++) {
        //     for(int j = 0; j < n; j ++) {
        //         cout << memo[i][j][0] << "," << memo[i][j][1] << "| ";
        //     }
        //     cout << endl;
        // }
        vector<int> def = {0, 0};
        vector<int> rAns = {
            (int)(ans.first % MOD),
            (int) ans.second
        };
        return ans.first == INT_MIN ? def: rAns;
    }
};