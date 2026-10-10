#include <bits/stdc++.h>
using namespace std;

// 36. Valid Sudoku [M]
// LeetCode valid-sudoku

class Solution {
public:
    unordered_map<int, unordered_map<char, bool>> rowSeen;
    unordered_map<int, unordered_map<char, bool>> colSeen;
    unordered_map<long long, unordered_map<char, bool>> blockSeen;
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i ++) {
            for(int j = 0; j < board[i].size(); j ++) {
                char c = board[i][j];                
                if(!isalnum(c)) continue;
                if(rowSeen[i].contains(c)) return false;
                if(colSeen[j].contains(c)) return false;
                long long key = (long long) (i / 3) << 32 | j / 3;
                if(blockSeen[key].contains(c)) return false;
                rowSeen[i][c] = true;
                colSeen[j][c] = true;
                blockSeen[key][c] = true;
            }
        }
        return true;
    }
};