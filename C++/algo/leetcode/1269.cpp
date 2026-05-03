#include <bits/stdc++.h>
using namespace std;

// 1269. Number of Ways to Stay in the Same Place After Some Steps [H]
// LeetCode number-of-ways-to-stay-in-the-same-place-after-some-steps

int MOD = 1e9 + 7;
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        // int memo[500][500];
        // memset(memo, -1, sizeof(memo));
        // auto dfs = [&] (this auto&& dfs, int pos, int cnt) {
        //     if(cnt == steps) return pos == 0 ? 1 : 0;
        //     if(memo[pos][cnt] != -1) return memo[pos][cnt];
        //     int ans = dfs(pos, cnt + 1) % MOD;
        //     if(pos + 1 < arrLen) ans = (ans + dfs(pos + 1, cnt + 1)) % MOD;
        //     if(pos - 1 >= 0) ans = (ans + dfs(pos - 1, cnt + 1)) % MOD;
        //     return memo[pos][cnt] = ans;
        // };
        int maxPos = min(steps / 2 + 1, arrLen);
        vector dp(maxPos + 1, vector(steps + 1, 0 ));
        dp[0][steps] = 1;
        for(int cnt = steps - 1; cnt >= 0; --cnt) {
            for(int pos = 0; pos < maxPos; ++pos) {
                dp[pos][cnt]  = dp[pos][cnt + 1];
                if(pos + 1 < arrLen) dp[pos][cnt]  = (dp[pos][cnt] + dp[pos + 1][cnt + 1]) % MOD;
                if(pos - 1 >= 0) dp[pos][cnt]   = (dp[pos][cnt]  + dp[pos - 1][cnt + 1]) % MOD;
            }
        }
        return dp[0][0];
    }
};