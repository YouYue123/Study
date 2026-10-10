
#include <bits/stdc++.h>
using namespace std;

class Game {
private:
    int winK;
    unordered_map<int, vector<char>> board;
    int cntDir (int r, int c, pair<int, int>& dir, char player) {
        int cnt = 0;
        int curR = r + dir.first;
        int curC = c + dir.second;
        while(board.contains(curC)) {
            auto& col = board[curC];
            if(curR < 0 || curR >= (int)col.size()) break;
            if(col[curR] != player) break;
            cnt += 1;
            curR += dir.first;
            curC += dir.second;
        }
        return cnt;
    }
    bool isWinner(int r, int c, char player) {
        vector<pair<int, int>> dirs = {
            {0, 1}, {1, 0}, {1, 1}, {1, -1}
        };
        for(auto d : dirs) {
            pair<int, int> reverseD = { -d.first, -d.second };
            int total = 1 + cntDir(r, c, d, player) + cntDir(r, c, reverseD, player);
            if(total >= winK) return  true;
        }
        return false;
    }
public:
    Game(int winK): winK(winK) {}
    char move(char player, int c) {
        board[c].push_back(player);
        int r = (int) board[c].size() - 1;
        if(isWinner(r, c, player)) {
            return player;
        }
        return '0';
    }
    void printBoard () {
        if (board.empty()) return;
        vector<vector<char>> rows;
        vector<int> cols;
        int minCol = 2e9, maxCol = -2e9, maxRow = 0;
        for(auto& [col, vec] : board) {
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
            maxRow = max(maxRow, (int)vec.size());
        }
        for(int r = maxRow - 1; r >= 0; r --) {
            for(int c = minCol; c <= maxCol; c ++) {
                if(board.contains(c) && r < board[c].size()) {
                    cout << board[c][r] << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        for (int c = minCol; c <= maxCol; c++) cout << "--";
        cout << "\n";
        for (int c = minCol; c <= maxCol; c++) cout << c << " ";
        cout << "\n-------------------\n" << endl;
    }
};

int main() {
    auto game = Game(4);
    
    game.move('R', -1);
    game.move('B', -1);
    game.move('B', -1);
    game.move('B', 0);
    game.move('R', 0);
    game.move('R', 1);
    game.move('B', 1);
    game.move('R', 2);
    game.move('B', 3);
    game.move('B', 4);
    game.printBoard();

    game.move('R', 2);

    game.printBoard();
    game.move('R', 0);
    game.move('R', 0);
    cout << "Winner! : " << game.move('R', 0) << endl;
    game.printBoard();

}