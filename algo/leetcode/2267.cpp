#include <bits/stdc++.h>
using namespace std;

// 2267.  Check if There Is a Valid Parentheses String Path [H]
// LeetCode check-if-there-is-a-valid-parentheses-string-path

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
if ((m + n) % 2 == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }      
        vector<vector<vector<int>>> memo(
            m,
            vector<vector<int>>(
                n,
                vector<int>((m * n) / 2 + 1, 0)
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int j, int openCnt) {
            if(i >= m || j >= n) return false;
            if(openCnt < 0) return false;
            if(openCnt > m * n / 2) return false;
            char c = grid[i][j];
            if(i == m - 1 && j == n - 1) return openCnt == 1;
            if(memo[i][j][openCnt] != 0) {
                return memo[i][j][openCnt] == 1 ? true : false;
            }
            bool ans = false;
            if(c == '(') {
                ans = dfs(i + 1, j, openCnt + 1) || dfs(i, j + 1, openCnt + 1);
            } else {
                ans = dfs(i + 1, j, openCnt - 1) || dfs(i, j + 1, openCnt - 1);
            }
            if(ans) {
                memo[i][j][openCnt] = 1;
            } else {
                memo[i][j][openCnt] = 2;
            }
            return ans;
        };
        
        return dfs(0, 0, 0);
    }
};