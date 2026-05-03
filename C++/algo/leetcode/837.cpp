// 837. New 21 Game [M]
// LeetCode new-21-game

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k + maxPts < n) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double curSum = dp[0];
        double ans = 0.0;
        for(int i = 1; i <= n; i ++) {
            dp[i] = curSum / maxPts;
            if(i < k) curSum += dp[i];
            else ans += dp[i];
            if(i - maxPts >= 0) curSum -= dp[i - maxPts]; 
        }
        // for(int i = 0; i <= n; i ++) {
        //     cout << dp[i] << endl;
        // }
        return ans;
    }
};