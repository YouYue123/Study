#include <bits/stdc++.h>
using namespace std;

// 85. Maximal Rectangle [H]
// LeetCode maximal-rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m =  matrix.size(), n = matrix[0].size();
        vector height(m, vector(n, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '1') {
                    height[i][j] = (i > 0 ? height[i - 1][j] + 1 : 1);
                } else {
                    height[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            stack<int> st;
            for(int j = 0; j <= n; j ++) {
                int cur_h = (j == n) ? 0 : height[i][j];
                while(!st.empty() && height[i][st.top()] > cur_h) {
                    int h = height[i][st.top()];
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    ans = max(ans, h * (j - left - 1));
                }
                st.push(j);
            }
        }
        return ans;
    }
};