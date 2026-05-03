#include <bits/stdc++.h>
using namespace std;

// 1275. Find Winner on a Tic Tac Toe Game [E]
// LeetCode find-winner-on-a-tic-tac-toe-game

class Solution {
private: 
    vector<vector<char>> board;
    bool checkWin(char c) {
        for(int i = 0; i < 3; i ++) {
            if(board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
            if(board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
        }
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if(board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    }
    bool isFull() {
        for(int i = 0; i < 3; i ++) {
            for(int j = 0; j < 3; j ++) {
                if(board[i][j] == ' ') return false;
            }
        }
        return true;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        board.assign(3, vector(3, ' '));
        bool isX = true;
        for(auto& move : moves)  {
            int x = move[0], y = move[1];
            board[x][y] = isX ? 'X' : 'O';
            isX = !isX;
        }
        if(checkWin('X')) return "A";
        if(checkWin('O')) return "B";
        return isFull() ? "Draw" : "Pending"; 
    }
};