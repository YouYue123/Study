#include <vector>
#include <iostream>
using namespace std;

class Connect4 {
    const int ROWS = 6;
    const int COLS = 7;
    vector<vector<int>> board; // 0:空, 1:玩家1, 2:玩家2 [10]
    bool end = false;
public:
    Connect4() : board(ROWS, vector<int>(COLS, 0)) {}

    bool makeMove(int col, int player) {
        if(end) {
            cout << "END!" << endl;
            return false;
        }
        if (col < 0 || col >= COLS) return false;
        for (int row = 0; row < ROWS; row ++) {
            if (board[row][col] == 0) {
                board[row][col] = player;
                if (checkWin(row, col, player)) {
                    cout << "Player " << player << " wins!\n";
                    end = true;
                }
                return true;
            }
        }
        return false; // 该列已满 [9]
    }

    void printBoard() {
        cout << "\n  0 1 2 3 4 5 6" << endl;
        for (int row = ROWS - 1; row >= 0; row--) { 
            cout << "| ";
            for (int col = 0; col < COLS; ++col) {
                if (board[row][col] == 0) cout << ". ";
                else cout << (board[row][col] == 1 ? "X " : "O ");
            }
            cout << "|" << endl;
        }
        cout << "  ---------------" << endl;
    }

private:
    bool isValid(int row, int col) {
        return row >= 0 && col >= 0 && row < ROWS && col < COLS;
    }
    bool checkWin(int r, int c, int p) {
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {1, 1}, {-1, 1}
        };
        vector<int> signs = {1, -1};
        if(board[r][c] != p) return false;
        for(auto& dir: dirs) {
            int cnt = 1;
            for(int sign : signs) {
                int row = r + dir.first * sign, col = c + dir.second * sign;
                while(isValid(row, col) && board[row][col] == p) {
                    cnt += 1;
                    if(cnt == 4) return true;
                    row += dir.first * sign;
                    col += dir.second * sign;
                }
            }
        }
        return false;
    }
};

// 测试案例
int main() {
    Connect4 game;

    cout << "--- Test Case 1: Vertical Win (Player 1) ---" << endl;
    // 玩家 1 在第 3 列连落 4 子
    for(int i = 0; i < 4; ++i) {
        game.makeMove(3, 1);
        game.makeMove(0, 2); // 玩家 2 随便在第 0 列落子
    }
    game.printBoard();

    cout << "\n--- Test Case 2: Horizontal Win (Player 2) ---" << endl;
    Connect4 game2;
    // 玩家 2 在底部第 1, 2, 3, 4 列连成一线
    game2.makeMove(1, 2);
    game2.makeMove(1, 1); // 挡一下上面
    game2.makeMove(2, 2);
    game2.makeMove(2, 1);
    game2.makeMove(3, 2);
    game2.makeMove(3, 1);
    game2.makeMove(4, 2); // 这一步应该触发胜利
    game2.printBoard();

    cout << "\n--- Test Case 3: Diagonal Win ---" << endl;
    Connect4 game3;
    /* 构造一个对角线胜利的形状:
       . . . .
       . . . 1
       . . 1 2
       . 1 2 2
       1 2 2 1
    */
    game3.makeMove(0, 1); // 1
    game3.makeMove(1, 2); // 2
    game3.makeMove(1, 1); // 1
    game3.makeMove(2, 2); // 2
    game3.makeMove(2, 2); // 2
    game3.makeMove(2, 1); // 1
    game3.makeMove(3, 2); // 2
    game3.makeMove(3, 2); // 2
    game3.makeMove(3, 2); // 2
    game3.makeMove(3, 1); // 1 (胜利落子)
    game3.printBoard();

    return 0;
}