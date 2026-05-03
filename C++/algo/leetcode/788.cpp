// 788. Rotated Digits [M]
// LeetCode rotated-digits

class Solution {
public:
    int rotatedDigits(int n) {
        vector memo(n + 1, vector(2, -1));
        auto dfs = [&] (this auto&& dfs, int cur, bool is_same) {
            if(cur > n) return 0;
            if(memo[cur][is_same] != -1) return memo[cur][is_same];
            int ans = 0;
            for(int i = 0; i <= 9; i ++) {
                if(i == 0 && cur == 0) continue;
                int nxt = cur * 10 + i;
                if(nxt > n) break;
                if(i == 0 || i == 1 || i == 8) {
                    ans += dfs(nxt, is_same) + (is_same ? 0 : 1);
                } else if(i == 2 || i == 5 || i == 6 || i == 9) {
                    ans += dfs(nxt, false) + 1;
                }
            }
            return memo[cur][is_same] = ans;
        };
        return dfs(0, true);
    }
};