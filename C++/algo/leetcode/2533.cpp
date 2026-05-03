// 2533. Number of Good Binary Strings [M]
// LeetCode number-of-good-binary-strings

int MOD = 1e9 + 7;
class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        vector<int> memo(1e5 + 1, -1);
        auto dfs = [&](this auto&&dfs, int len) {
            if(len == 0) return 1;
            int ans = 0;
            if(memo[len] != -1) return memo[len];
            if(len >= oneGroup) ans = ((long long)ans + dfs(len - oneGroup)) % MOD;
            if(len >= zeroGroup) ans = ((long long)ans + dfs(len - zeroGroup)) % MOD;
            return memo[len] = ans;
        };
        int ans = 0;
        for(int len = minLength; len <= maxLength; len ++) {
            ans = ((long long) ans + dfs(len)) % MOD;
        }
        return ans;
    }
};