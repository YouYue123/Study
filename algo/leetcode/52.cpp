#include <bits/stdc++.h>
using namespace std;

// 52. N-Queens II [H]
// LeetCode n-queens-ii

class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> dict;
    int ans = 0;
    bool isValid (int n,int row, int col) {
        for(int i = 0; i < row; i ++) {
            if(dict[i][col]) return false;
            int leftDiagonal = col - (row - i);
            if(leftDiagonal >= 0 &&dict[i][leftDiagonal]) return false;
            int rightDiagnol = col + (row - i);
            if(rightDiagnol < n && dict[i][rightDiagnol]) return false;
        }
        return true;
    }
    void dfs(int n, int row) {
        if(n == row) {
            ans += 1;
            return;
        }
        for(int col = 0; col < n; col ++) {
            if(!isValid(n , row, col)) continue;
            dict[row][col] = true;
            dfs(n, row + 1);
            dict[row][col] = false;
        }
    }
    int totalNQueens(int n) {
        dfs(n, 0);
        return ans;
    }
};