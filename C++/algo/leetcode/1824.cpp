// 1824. Minimum Sideway Jumps [M]
// LeetCode minimum-sideway-jumps

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> memo(
            n + 1, 
            vector<int>(4, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == n) return 0;
            if(obstacles[i] == j) return INT_MAX / 2;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INT_MAX / 2;
            for(int lane = 1; lane <= 3; lane ++) {
                if(obstacles[i] == lane) continue;
                if(lane == j) {
                    ans = min(ans, dfs(i + 1, lane));
                } else {
                    ans = min(ans, dfs(i + 1, lane) + 1);
                }
            }
            return memo[i][j] = ans;
        };
        return dfs(0, 2);
    }
};