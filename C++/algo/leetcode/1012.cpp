// 1012. Numbers With Repeated Digits [H]
// LeetCode numbers-with-repeated-digits

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        vector memo(
            s.size(),
            vector(1 << 10, vector(2, -1))
        );        
        auto dfs = [&] (this auto&& dfs, int i, int mask, bool is_limit, bool is_num, bool is_repeat) {
            if(i == s.size()) return is_repeat ? 1 : 0;
            if(!is_limit && is_num && memo[i][mask][is_repeat] != -1) return memo[i][mask][is_repeat];
            int ans = is_num ? 0 : dfs(i + 1, mask, false, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for(int d = is_num ? 0 : 1; d <= up; d ++) {
                bool has_shown = (mask & (1 << d)) != 0;
                ans += dfs(
                    i + 1,
                    mask | (1 << d), 
                    is_limit && d == up, 
                    true,
                    is_repeat || has_shown
                );
            } 
            if(!is_limit && is_num) {
                memo[i][mask][is_repeat] = ans;
            }
            return ans;
        } ;
        return dfs(0, 0, true, false, false);
    }
};