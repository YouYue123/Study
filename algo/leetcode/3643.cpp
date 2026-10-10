#include <bits/stdc++.h>
using namespace std;

// 3643. Flip Square Submatrix Vertically [E]
// LeetCode flip-square-submatrix-vertically

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        int c = y;
        while(c < y + k) {
            int top = x, bottom = x + k - 1;;
            while(top < bottom) {
                swap(grid[top][c], grid[bottom][c]);
                top += 1;
                bottom -= 1;
            }
            c += 1;
        }
        return grid;
    }
};