#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m = evil.size();
        auto get_lps = [&] () {
            vector<int> lps(m, 0);
            for(int i = 1, match = 0; i < m; i ++) {
                while(match > 0 && evil[i] != evil[match]) match = lps[match - 1];
                if(evil[i] == evil[match]) match += 1;
                lps[i] = match;
            }
            return lps;
        };
        auto lps = get_lps();
        auto get_next_p = [&] (int p, char c) {
            while(p > 0 && c != evil[p]) p = lps[p - 1];
            if(c == evil[p]) p += 1;
            return p;
        };
        vector memo(n, vector(m, vector(2, vector(2, -1LL))));
        auto dfs = [&] (this auto&& dfs, int i,  int p, bool is_low, bool is_high) -> long long {
            if(i == n) return 1LL;
            if(memo[i][p][is_low][is_high] != -1) return memo[i][p][is_low][is_high];
            char low = is_low ? s1[i] : 'a';
            char high = is_high ? s2[i] : 'z';
            long long ans = 0;
            for(char cur = low; cur <= high; cur ++) {
                if(cur == evil[p] && p == m - 1) continue;
                ans = (
                    ans + 
                    dfs(
                        i + 1, 
                        cur == evil[p] ? p + 1 : get_next_p(p, cur),
                        is_low && s1[i] == cur, 
                        is_high && s2[i] == cur
                    )
                ) % MOD;
            }
            return memo[i][p][is_low][is_high] = ans;
        };
        return dfs(0, 0, true, true) ; 
    }
};