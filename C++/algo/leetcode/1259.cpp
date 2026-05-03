// 1259. Handshakes That Don't Cross [H]
// LeetCode handshakes-that-dont-cross

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int numPeople) {
        vector memo(numPeople + 1, -1LL);
        auto dfs = [&] (this auto&& dfs, int i) -> long long {
            if(i == 0) return 1;
            if(memo[i] != -1) return memo[i];
            long long ans = 0;
            for(int k = 2; k <= i; k += 2) {
                ans = (ans + (dfs(k - 2) * dfs(i - k)) % MOD) % MOD;
            }
            return memo[i] = ans;
        };
        return dfs(numPeople);
    }
};