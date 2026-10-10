#include <bits/stdc++.h>
using namespace std;

// 1981. Minimize the Difference Between Target and Chosen Elements [M]
// LeetCode minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        // vector memo(n + 1, INT_MAX);
        vector memo(
            n + 1,
            vector(
                70 * 70 + 1,
                -1
            )
        );
        auto dfs =[&] (this auto&& dfs, int row, int cur) {
            int diff = abs(cur - target);
            if(row == n) return diff;
            if(memo[row][cur] != -1) return memo[row][cur];
            // cout << diff << " " << ans << endl;
            int ans = INT_MAX;
            for(int c = 0; c < m; c ++) {
                ans = min(ans, dfs(row + 1, cur + mat[row][c]));
            }
            return memo[row][cur] = ans;
        };
        // dfs(0, 0);
        // for(int num : memo) cout << num << endl;
        return dfs(0, 0);
    }
};