// 2320. Count Number of Ways to Place Houses [M]
// LeetCode count-number-of-ways-to-place-houses

int MOD = 1e9 + 7;
class Solution {
public:
    int countHousePlacements(int n) {
        vector<int> memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int x) {
            if(x >= n) return 0;
            if(memo[x] != -1) return memo[x];
            int a = dfs(x + 2) + 1;
            int b = dfs(x + 1);
            return memo[x] = ((long long)a + b) % MOD;
        };
        long long ans = ((long long)1 + dfs(0)) % MOD;
        return (ans * ans) % MOD;
    }
};