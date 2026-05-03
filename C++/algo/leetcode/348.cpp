// 348. Design Tic-Tac-Toe [M]
// LeetCode design-tic-tac-toe

class TicTacToe {
private:
    vector<int> row_sum;
    vector<int> col_sum;
    vector<int> diag_sum;
    int n;
public:
    TicTacToe(int n): n(n) {
        row_sum.assign(n, 0);
        col_sum.assign(n, 0);
        diag_sum.assign(2, 0);
    }
    
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;
        row_sum[row] += val;
        col_sum[col] += val;
        if(row == col || (row + col == n - 1)) {
            if(row == col) {
                diag_sum[0] += val;
            } 
            if(row + col == n - 1){
                diag_sum[1] += val;
            }
        }
        if(row_sum[row] == n || row_sum[row] == -n) return player;
        if(col_sum[col] == n || col_sum[col] == -n) return player;
        if(diag_sum[0] == n  || diag_sum[0] == -n) return player;
        if(diag_sum[1] == n || diag_sum[1] == -n) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */