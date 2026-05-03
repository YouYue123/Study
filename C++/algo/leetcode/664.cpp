// 664. Strange Printer [H]
// LeetCode strange-printer

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == j) return 1;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INF;
            if(s[i] == s[j]) {
                ans = dfs(i, j - 1);
            } else {
                for(int k = i; k < j; k ++) {
                    ans = min(
                        ans,
                        dfs(i, k) + dfs(k + 1, j)
                    );
                }
            }
            return memo[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};