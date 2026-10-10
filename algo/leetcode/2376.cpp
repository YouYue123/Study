#include <bits/stdc++.h>
using namespace std;

// 2376. Count Special Integers [H]
// LeetCode count-special-integers

class Solution {
public:
    int countSpecialNumbers(int n) {
        string num_s = to_string(n);
        vector memo(
            num_s.size(), 
            vector(
                (1 << 10) - 1, 
                vector(2, vector(2, -1))
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int mask, bool is_limit, bool is_num) {
            if(i == num_s.size()) return is_num ? 1 : 0;
            if(memo[i][mask][is_limit][is_num] != -1) return memo[i][mask][is_limit][is_num];
            int ans = is_num ? 0 : dfs(i + 1, mask, false, false);
            int up = is_limit ? num_s[i] - '0' : 9;
            for(int d = (is_num ? 0 : 1); d <= up; d ++) {
                if((mask & (1 << d)) == 0) {
                    ans += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            }
            return memo[i][mask][is_limit][is_num] = ans;
        };

        return dfs(0, 0, true, false);
    }
};