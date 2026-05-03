// 3129. Find All Possible Stable Binary Arrays I [M]
// LeetCode find-all-possible-stable-binary-arrays-i

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector memo(
            zero + 1, 
            vector(
                one + 1,
                vector(
                    2,
                    -1LL
                )
            )
        );

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> long long {
            if (i == 0) return k == 1 && j <= limit;
            if (j == 0) return k == 0 && i <= limit;
            if(memo[i][j][k] != -1) return memo[i][j][k];
            long long ans = 0;
            if (k == 0) {
                // + MOD 保证答案非负
                ans = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1)) % MOD;
                if(i > limit) {
                    ans = (ans + MOD - dfs(i - limit - 1, j, 1)) % MOD;
                }
            } else {
                ans =  (dfs(i, j - 1, 0) + dfs(i, j - 1, 1)) % MOD;
                if(j > limit) {
                    ans = (ans + MOD - dfs(i, j - limit - 1, 0)) % MOD;
                }
            }
            return memo[i][j][k] = ans;
        };

        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    }
};