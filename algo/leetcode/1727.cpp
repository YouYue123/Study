#include <bits/stdc++.h>
using namespace std;

// 1727. Largest Submatrix With Rearrangements [M]
// LeetCode largest-submatrix-with-rearrangements

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector cnt(m, vector(n, 0));
        for(int r = 0; r < m; r ++) {
            for(int c = 0; c < n; c ++) {
                // 如果当前是 1，累加上一行的高度；如果当前是 0，高度直接重置为 0
                if (matrix[r][c] == 1) {
                    cnt[r][c] = (r > 0 ? cnt[r - 1][c] : 0) + 1;
                } else {
                    cnt[r][c] = 0;
                }            
            }
        }
        int ans = 0;
        for(int r = 0; r < m; r ++) {
            int rCnt = 0;
            sort(cnt[r].begin(), cnt[r].end(), greater<>()); 
            for(int c = 0; c < n; c++) {
                ans = max(ans, cnt[r][c] * (c + 1));
            }
        }
        return ans;
    }
};