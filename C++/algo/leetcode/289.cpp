// 289. Game of Life [M]
// LeetCode game-of-life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) { 
        list<pair<int, int>> neighbors = {
            {-1,-1}, {1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {1,-1}, {-1,1}
        };
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int n_sum = 0;
                for(auto& N: neighbors){
                    int n_i = N.first + i;
                    int n_j = N.second + j;
                    n_sum += (n_j < n && n_i < m && n_i > -1 && n_j > -1)? (board[n_i][n_j] % 2):0;
                }
                if((n_sum < 2 || n_sum > 3) && board[i][j] == 1) board[i][j] = 3;
                if(n_sum == 3 && board[i][j] == 0) board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 3) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};