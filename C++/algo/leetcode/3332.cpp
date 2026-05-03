// 3332. Maximum Points Tourist Can Earn [M]
// LeetCode maximum-points-tourist-can-earn

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        // vector memo(n, vector(k, -1));
        // auto dfs = [&] (this auto&& dfs, int i, int day) {
        //     if(day == k) return 0;
        //     if(i == n) return -INF;
        //     if(memo[i][day] != -1) return memo[i][day];
        //     int ans = dfs(i, day + 1) + stayScore[day][i];
        //     for(int j = 0; j < n; j ++) {
        //         if(j == i) continue;
        //         ans = max(
        //             ans,
        //             dfs(j, day + 1) + travelScore[i][j]
        //         );
        //     }
        //     return memo[i][day] = ans;
        // };
        // int ans = -INF;
        // for(int i = 0; i < n; i ++) {
        //     ans = max(ans, dfs(i, 0));
        // }
        // return ans;
        int ans = 0;
        vector dp(n, vector(k + 1, 0));
        for(int day = k - 1; day >= 0; day --) {
            for(int i = 0; i < n; i++) {
                dp[i][day] = dp[i][day + 1] + stayScore[day][i];
                for(int j = 0; j < n; j ++) {
                    if(j == i) continue;
                    dp[i][day] = max(dp[i][day], dp[j][day + 1] + travelScore[i][j]);
                }
                ans = max(ans, dp[i][day]);
            }
        }
        return ans;
    }
};