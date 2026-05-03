// 2318. Number of Distinct Roll Sequences [H]
// LeetCode number-of-distinct-roll-sequences

int MOD = 1e9 + 7;
class Solution {
public:
    int distinctSequences(int n) {
        vector memo(n, vector(8, vector(8, -1)));
        auto dfs = [&](this auto&& dfs, int i, int prev, int prevPrev) {
            if(i == n) return 1;
            if(memo[i][prev][prevPrev] != -1) return memo[i][prev][prevPrev];
            int ans = 0;
            for(int cur = 1; cur <= 6; cur += 1) {
                if(gcd(prev, cur) != 1) continue;
                if(prev == cur || prevPrev == cur) continue;
                ans = (ans + dfs(i + 1, cur, prev)) % MOD;
            }
            return memo[i][prev][prevPrev] = ans;
        };
        return dfs(0, 7, 7);
    }
};