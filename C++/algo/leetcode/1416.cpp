// 1416. Restore The Array [H]
// LeetCode restore-the-array

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector memo(n, -1LL);
        auto dfs = [&] (this auto&& dfs, int i) -> long long {
            if(i == n) return 1;
            if(s[i] == '0') return 0;
            if(memo[i] != -1) return memo[i];
            long long cur = 0;
            long long ans = 0;
            for(int j = i; j < n; j ++) {
                cur = cur * 10 + (s[j] - '0');
                if(cur > k) break;
                ans = (ans + dfs(j + 1)) % MOD;
            }
            return memo[i] = ans;
        };

        return dfs(0);
    }
};