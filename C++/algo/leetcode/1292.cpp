#include <bits/stdc++.h>
using namespace std;

// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold [M]
// LeetCode maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector presum(m + 1, vector(n + 1, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + mat[i][j];
            }
        }
        int ans = 0;
        auto query = [&] (int x1, int y1, int x2, int y2) {
            int left = presum[x2 + 1][y1];
            int top  =  presum[x1][y2 + 1];
            return presum[x2 + 1][y2 + 1] - top - left + presum[x1][y1];
        };
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                while(i + ans < m && j + ans < n && query(i, j, i + ans, j + ans) <= threshold) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};