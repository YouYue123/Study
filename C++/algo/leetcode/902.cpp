// 902. Numbers At Most N Given Digit Set [H]
// LeetCode numbers-at-most-n-given-digit-set

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        auto s = to_string(n);
        vector memo(s.size(), vector(2, vector(2, -1)));
        auto dfs = [&](this auto&& dfs, int i, bool is_limit, bool is_num) {
            if(i == s.size()) return is_num ? 1 : 0;
            if(memo[i][is_limit][is_num] != -1) return memo[i][is_limit][is_num];
            int ans = is_num ? 0 : dfs(i + 1, false, false);
            auto up = is_limit ? s[i] : '9';
            for(string d : digits) {
                if(d[0] > up) break;
                ans += dfs(i + 1, is_limit && d[0] == up, true);
            }
            return memo[i][is_limit][is_num] = ans;
        };
        return dfs(0, true, false);
    }
};