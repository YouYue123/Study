// 3183. The Number of Ways to Make the Sum [M]
// LeetCode the-number-of-ways-to-make-the-sum

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int n) {
        vector<int> coins = {1, 2, 6};
        int m = coins.size();
        long long ans = 0;
        for(int k = 0; k <= 2; ++k) {
            vector memo(
                m + 1,
                vector(
                    n + 1,
                    -1LL
                )
            );
            auto dfs = [&](this auto&& dfs, int i, int amt) {
                if(amt < 0) return 0LL;
                if(amt == 0) return 1LL;
                if(i >= m) return 0LL;
                if(memo[i][amt] != -1) return memo[i][amt];
                return memo[i][amt] = (
                    dfs(i, amt - coins[i]) +
                    dfs(i + 1, amt)
                ) % MOD;
            };
            ans = (ans + dfs(0, n - k * 4)) % MOD;
        }
        return ans;
    }
};