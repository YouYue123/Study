// 2222. Number of Ways to Select Buildings [M]
// LeetCode number-of-ways-to-select-buildings

class Solution {
public:
    long long numberOfWays(string s) {
        long long cnt0 = 0, cnt1 = 0;
        long long cnt01 = 0, cnt10 = 0;
        long long ans = 0;
        for(char c : s) {
            if(c == '0') {
                cnt10 += cnt1;
                cnt0 += 1;
                ans += cnt01;
            } else {
                cnt01 += cnt0;
                cnt1 += 1;
                ans += cnt10;
            }
        }
        return ans;
    }
};