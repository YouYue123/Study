// 696. Count Binary Substrings [E]
// LeetCode count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int oneCnt = 0, zeroCnt = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(i > 0 && s[i - 1] != s[i]) {
                if(s[i] == '0') zeroCnt = 0;
                else oneCnt = 0;
            }
            if(c == '0') {
                zeroCnt += 1;
                if(zeroCnt <= oneCnt) ans += 1;
            } else {
                oneCnt += 1;
                if(oneCnt <= zeroCnt) ans += 1;
            }
        }
        return ans;
    }
};