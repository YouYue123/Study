// 1513. Number of Substrings With Only 1s [M]
// LeetCode number-of-substrings-with-only-1s

int MOD = 1e9 + 7;
class Solution {
public:
    int numSub(string s) {
        int lastZeroPos = -1;
        int ans = 0;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if(c == '0') lastZeroPos = i;
            ans = ((long long)ans + i - lastZeroPos) % MOD;
        }
        return ans;
    }
};