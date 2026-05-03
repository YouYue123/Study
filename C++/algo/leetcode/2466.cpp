// 2466. Count Ways To Build Good Strings [M]
// LeetCode count-ways-to-build-good-strings

int MOD = 1e9 + 7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(1e5 + 1, -1);
        auto dfs = [&](this auto&& dfs, int len) {
            if(len == 0) return 1;
            int ans = 0;
            if(memo[len] != -1) return memo[len];
            if(len >= zero) ans = ((long long)ans + dfs(len - zero)) % MOD;
            if(len >= one) ans = ((long long)ans + dfs(len - one)) % MOD;
            return memo[len] = ans;
        };
        int ans = 0;
        for(int len = low; len <= high; len ++) {
            ans = ((long long)ans + dfs(len)) % MOD;
        }
        return ans;
    }
};