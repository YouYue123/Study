// 1262. Greatest Sum Divisible by Three [M]
// LeetCode greatest-sum-divisible-by-three

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        // vector memo(n, vector(3, -1));
        // auto dfs = [&] (this auto&& dfs, int i, int res) {
        //     if(i == n) return res == 0 ? 0 : -INF;
        //     if(memo[i][res] != -1) return memo[i][res];
        //     int ans = max(
        //         dfs(i + 1, res),
        //         dfs(i + 1, (res + nums[i]) % 3) + nums[i]
        //     );
        //     return memo[i][res] = ans;
        // };
        vector<int> dp = {0, -INF, -INF};
        dp[nums[0] % 3] = nums[0];
        // dp[0][nums[0] % 3] = nums[0];
        for(int i = 1; i < n; i ++) {
            vector<int> nxtDp = dp;
            for(int res = 0; res < 3; res ++) {
                int prevRes = (res - (nums[i] % 3) + 3) % 3;
                nxtDp[res] = max({
                    dp[res],
                    dp[prevRes] + nums[i]
                });
            }
            dp = nxtDp;
        }
        return dp[0];
    }
};