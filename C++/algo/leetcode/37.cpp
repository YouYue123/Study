#include <bits/stdc++.h>
using namespace std;

// 37. Sudoku Solver [H]
// LeetCode sudoku-solver

class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> rowDict;
    unordered_map<int, unordered_map<int, bool>> colDict;
    unordered_map<int, unordered_map<int, bool>> blockDict;
    int target = 0;

    int getBlockIndex(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }

    bool isValid(int row, int col, int num) {
        if (rowDict[row][num]) return false;
        if (colDict[col][num]) return false;
        int blockIndex = getBlockIndex(row, col);
        if (blockDict[blockIndex][num]) return false;
        return true;
    }

    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return target == 0;
        }
        if (col == 9) {
            return dfs(board, row + 1, 0);
        }
        if (board[row][col] != '.') return dfs(board, row, col + 1);
        for (int num = 1; num <= 9; ++num) {
            if (!isValid(row, col, num)) continue;
            board[row][col] = num + '0';
            int blockIndex = getBlockIndex(row, col);
            rowDict[row][num] = true;
            colDict[col][num] = true;
            blockDict[blockIndex][num] = true;
            target -= 1;
            if (dfs(board, row, col + 1)) return true;
            board[row][col] = '.';
            rowDict[row][num] = false;
            colDict[col][num] = false;
            blockDict[blockIndex][num] = false;
            target +=1;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    target += 1;
                    continue;
                }
                int num = board[i][j] - '0';
                rowDict[i][num] = true;
                colDict[j][num] = true;
                int blockIndex = getBlockIndex(i, j);
                blockDict[blockIndex][num] = true;
            }
        }
        dfs(board, 0, 0);
    }
};