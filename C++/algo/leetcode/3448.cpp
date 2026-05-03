// 3448. Count Substrings Divisible By Last Digit [H]
// LeetCode count-substrings-divisible-by-last-digit

class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long memo[n][10];
        long long ans = 0;
        for(int d = 1; d <= 9; d ++) {
            memset(memo, -1LL, sizeof(memo));
            auto dfs = [&] (this auto&& dfs, int i, int rem) -> long long {
                if(i < 0) return 0;
                if(memo[i][rem] != -1) return memo[i][rem];
                long long ans = 0;
                int num = s[i] - '0';
                if(num % d == rem) ans += 1;
                for(int preRem = 0; preRem < d; preRem ++) {
                    if((preRem * 10 + num) % d == rem) ans += dfs(i - 1, preRem);
                }
                return memo[i][rem] = ans;
            };
            for(int i = 0; i < n; i ++) {
                if(s[i] - '0' == d) {
                    ans += dfs(i, 0);
                }
            }
        }
        return ans;
    }
};