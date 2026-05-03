// 639. Decode Ways II [H]
// LeetCode decode-ways-ii

int MOD = 1e9 + 7;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector memo(n, -1LL);
        auto dfs = [&] (this auto&& dfs, int i) -> long long {
            if(i == n) return 1;
            if(s[i] == '0') return 0;
            if(memo[i] != -1) return memo[i];
            int ans = 0;
            if(s[i] == '*') {
                ans = dfs(i + 1) * 9 % MOD;
            } else {
                ans = dfs(i + 1);
            }
            if(s[i] == '1' || s[i] == '*') {
                if(i + 1 < n) {
                    if(s[i + 1] == '*') {
                        ans = (ans + dfs(i + 2) * 9 % MOD) % MOD;
                    } else {
                        ans = (ans + dfs(i + 2)) % MOD;
                    }
                }
            }
            if(s[i] == '2' || s[i] == '*') {
                if(i + 1 < n) {
                    if((s[i + 1] >= '0' && s[i + 1] <= '6')) {
                        ans = (ans + dfs(i + 2)) % MOD;
                    } else if(s[i + 1] == '*'){
                        ans = (ans + dfs(i + 2) * 6 % MOD) % MOD;
                    }
                }
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};