#include <bits/stdc++.h>
using namespace std;

// 3906. Count Good Integers on a Grid Path [H]
// LeetCode count-good-integers-on-a-grid-path

class Solution {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        string low_s = to_string(l);
        string high_s = to_string(r);
        int n = high_s.size();
        int diff_lh = n - low_s.size();
        vector<array<long long, 10>> memo(n);
        vector<int8_t> in_path(n);
        int pos = n - 16;
        for(char d : directions) {
            if(pos >= 0) {
                in_path[pos] = true;
            }
            pos += d == 'R' ? 1 : 4;
        }
        in_path[n - 1] = true;
        auto dfs = [&] (this auto&& dfs, int i, int pre, bool limit_low, bool limit_high) -> long long {
            if(i == n) return 1;
            if(!limit_low && !limit_high && memo[i][pre] > 0) {
                return memo[i][pre] - 1;
            }
            int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;
            long long ans = 0;
            int start = in_path[i] ? max(lo, pre) : lo;
            for(int d = start; d <= hi; d ++) {
                ans += dfs(i + 1, in_path[i] ? d : pre, limit_low && d == lo, limit_high && d == hi);
                if(!limit_low && !limit_high) {
                    memo[i][pre] = ans + 1;
                }
            }
            return ans;
        };
        return dfs(0, 0, true, true);
    }
};