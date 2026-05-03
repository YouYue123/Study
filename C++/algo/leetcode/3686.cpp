// 3686. Number of Stable Subsequences [H]
// LeetCode number-of-stable-subsequences

int MOD = 1e9 + 7;
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        int memo[n][3][3];
        memset(memo, -1, sizeof(memo));
        auto dfs = [&] (this auto&& dfs, int i, int aP, int bP) {
            if(i == n) return 0;
            if(memo[i][aP][bP] != -1) return memo[i][aP][bP];
            int ans = dfs(i + 1, aP, bP);
            int cP = nums[i] % 2;
            if(aP == bP) {
                if(cP != aP) ans = (ans + dfs(i + 1, bP, cP) + 1) % MOD;
            } else {
                ans = (ans + dfs(i + 1, bP, cP) + 1) % MOD;
            }
            return memo[i][aP][bP] = ans;
        };

        return dfs(0, 2, 2);
    }
};