// 2167. Minimum Time to Remove All Cars Containing Illegal Goods [H]
// LeetCode minimum-time-to-remove-all-cars-containing-illegal-goods

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        int memo[n][2];
        memset(memo, -1, sizeof(memo));
        auto dfs = [&] (this auto&& dfs, int i, int state) {
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            int ans = 0;
            if(state == 0) {
                if(s[i] == '1') {
                    ans = min(
                        n - i,
                        1 + dfs(i + 1, 0)
                    );
                } else {
                    ans = min(
                        dfs(i + 1, 1),
                        1 + dfs(i + 1, 0)
                    );
                }
            } else if(state == 1) {
                if(s[i] == '1') {
                    ans = min(
                        n - i,
                        2 + dfs(i + 1, 1)
                    );
                } else {
                    ans = dfs(i + 1, 1);
                }
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};