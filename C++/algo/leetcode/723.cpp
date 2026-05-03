#include <bits/stdc++.h>
using namespace std;

// 723. Candy Crush [M]
// LeetCode candy-crush

class Solution {
public:
    int m, n;

    bool findAndCrush(vector<vector<int>>& board) {
        bool complete = true;

        // Check vertically adjacent candies
        for (int r = 1; r < m - 1; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (abs(board[r][c]) == abs(board[r - 1][c]) && abs(board[r][c]) == abs(board[r + 1][c])) {
                    board[r][c] = -abs(board[r][c]);
                    board[r - 1][c] = -abs(board[r - 1][c]);
                    board[r + 1][c] = -abs(board[r + 1][c]);
                    complete = false;
                }
            }
        }

        // Check horizontally adjacent candies
        for (int r = 0; r < m; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (abs(board[r][c]) == abs(board[r][c - 1]) && abs(board[r][c]) == abs(board[r][c + 1])) {
                    board[r][c] = -abs(board[r][c]);
                    board[r][c - 1] = -abs(board[r][c - 1]);
                    board[r][c + 1] = -abs(board[r][c + 1]);
                    complete = false;
                }
            }
        }

        // Set the value of each candy to be crushed as 0
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] < 0) {
                    board[r][c] = 0;
                }
            }
        }

        return complete;
    }

    void drop(vector<vector<int>>& board) {
        for (int c = 0; c < n; c++) {
            int lowestZero = -1;

            // Iterate over each column
            for (int r = m - 1; r >= 0; r--) {
                if (board[r][c] == 0) {
                    lowestZero = max(lowestZero, r);
                } else if (lowestZero >= 0) {
                    swap(board[r][c], board[lowestZero][c]);
                    lowestZero--;
                }
            }
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        // Continue with the three steps until we can no longer find any crushable candies.
        while (!findAndCrush(board)) {
            drop(board);
        }

        return board;
    }
};