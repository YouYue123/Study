#include <bits/stdc++.h>
using namespace std;

// 920. Number of Music Playlists [H]
// LeetCode number-of-music-playlists

int MOD = 1e9 + 7;
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        // vector memo(n + 1, vector(goal, -1LL));
        // auto dfs = [&](this auto&& dfs, int i, int j) {
        //     if(i > n) return 0LL;
        //     if(j == goal) return i == n ? 1LL : 0LL;
        //     if(memo[i][j] != -1) return memo[i][j];
        //     long long ans = 0;
        //     ans = (ans + (n - i) * dfs(i + 1, j + 1) % MOD) % MOD;
        //     ans = (ans + max(i - k, 0) * dfs(i, j + 1) % MOD) % MOD;
        //     return memo[i][j] = ans;
        // };
        
        vector dp(n + 1, vector(goal + 1, 0LL));
        dp[n][goal] = 1LL;
        for(int i = n; i >= 0; i --) {
            for(int j = goal - 1; j >= 0; j --) {
                long long ans = 0;
                if(i != n) ans = (ans + (n - i) * dp[i + 1][j + 1] % MOD) % MOD;
                ans = (ans + max(i - k, 0) * dp[i][j + 1] % MOD) % MOD;
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};