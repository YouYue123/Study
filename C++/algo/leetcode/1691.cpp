// 1691. Maximum Height by Stacking Cuboids  [H]
// LeetCode maximum-height-by-stacking-cuboids

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto & c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector memo(
            n,
            -1
        );
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if(i >= n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = cuboids[i][2];
            for(int j = 0; j < i; j ++) {
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    ans = max(
                        ans,
                        dfs(j) + cuboids[i][2]
                    );
                }
            }
            return memo[i] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};