// 794. Valid Tic-Tac-Toe State [M]
// LeetCode valid-tic-tac-toe-state

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (const string& row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                if (c == 'O') oCount++;
            }
        }

        // 基础数量检查：X 先手，只能比 O 多一个或相等
        if (!(xCount == oCount || xCount == oCount + 1)) {
            return false;
        }

        bool xWin = checkWin(board, 'X');
        bool oWin = checkWin(board, 'O');

        // 如果 X 赢了，O 不能赢，且 X 的数量必须比 O 多 1
        if (xWin) {
            if (oWin) return false;
            return xCount == oCount + 1;
        }

        // 如果 O 赢了，X 的数量必须等于 O
        if (oWin) {
            return xCount == oCount;
        }

        return true;
    }

private:
    bool checkWin(vector<string>& board, char p) {
        for (int i = 0; i < 3; i++) {
            // 检查行
            if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
            // 检查列
            if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
        }
        // 检查对角线
        if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
        if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
        
        return false;
    }
};