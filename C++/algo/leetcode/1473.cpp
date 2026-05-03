// 1473. Paint House III [H]
// LeetCode paint-house-iii

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector memo(
            m,
            vector(
                target + 1,
                vector(
                    n + 3,
                    -1
                )
            )
        );
        // cout << "n: " << n << " target: " << target << " m: " << m << endl; 
        auto dfs = [&] (this auto&& dfs, int i, int cnt, int prevColor) {
            if(cnt > target) return INT_MAX;
            if(i == m) return cnt == target ? 0 : INT_MAX;
            if(memo[i][cnt][prevColor] != -1) return memo[i][cnt][prevColor];
            int curColor = houses[i];
            int ans = INT_MAX;
            if(curColor == prevColor) {
                ans = dfs(i + 1, cnt, curColor);
            } else {
                if(curColor == 0) {
                    for(int nxColor = 1; nxColor <= n; nxColor ++) {
                        int remain = 0;
                        if(nxColor == prevColor) {
                            remain = dfs(i + 1, cnt, nxColor);
                        } else {
                            remain = dfs(i + 1, cnt + 1, nxColor);
                        }
                        if(remain != INT_MAX) ans = min(ans, cost[i][nxColor - 1] + remain);
                    }
                } else {
                    ans = dfs(i + 1, cnt + 1, curColor);
                }
            }
            return memo[i][cnt][prevColor] = ans;
        };
        return dfs(0, 0, n + 1) == INT_MAX ? -1 : dfs(0, 0, n + 1);
    }
};