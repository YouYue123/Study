// 1067. Digit Count in Range [H]
// LeetCode digit-count-in-range

class Solution {
public:
    int digitsCount(int d, int low, int high) {
        auto low_s = to_string(low);
        auto high_s = to_string(high);
        string pre_0 = "";
        for(int i = 0; i < high_s.size() - low_s.size(); i ++) {
            pre_0 += '0';
        }
        low_s = pre_0 + low_s;
        int memo[20][20][2][2][2];
        memset(memo, -1, sizeof(memo));
        auto dfs = [&] (this auto&& dfs, int i, int cnt, bool limit_high, bool limit_low, bool is_num) {
            if(i == high_s.size()) return cnt;
            if(memo[i][cnt][limit_high][limit_low][is_num] != -1) return memo[i][cnt][limit_high][limit_low][is_num];
            int lo = limit_low ? low_s[i] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;
            int ans = 0;
            for(int cur = lo; cur <= hi; cur ++) {
                bool nxt_is_num = is_num || (cur > 0);
                ans += dfs(
                    i + 1, 
                    cnt + ((nxt_is_num && cur == d) ? 1 : 0),
                    limit_high && cur == hi, 
                    limit_low && cur == lo,
                    nxt_is_num
                );
            }
            return memo[i][cnt][limit_high][limit_low][is_num] = ans;
        };
        return dfs(0, 0, true, true, false);
    }
};