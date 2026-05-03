// 1639. Number of Ways to Form a Target String Given a Dictionary [H]
// LeetCode number-of-ways-to-form-a-target-string-given-a-dictionary

int MOD = 1e9 + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for(auto& w : words) {
            for(int i = 0; i < w.size(); i ++) {
                freq[i][w[i] - 'a'] += 1;
            }
        }
        vector memo(
            n,
            vector(
                m, -1LL
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long{
            if(j < 0) return 1LL;
            if(i < 0 || i < j) return 0LL;
            if(memo[i][j] != -1) return memo[i][j];
            long long ans = dfs(i - 1, j);
            char c = target[j];
            if(freq[i][c - 'a'] > 0) {
                ans = (ans + (dfs(i - 1, j - 1) * freq[i][c - 'a']) % MOD) % MOD;
            }
            return memo[i][j] = ans;
        };
        return dfs(n - 1, m - 1);
    }
};