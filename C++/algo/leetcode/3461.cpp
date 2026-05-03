// 3461. Check If Digits Are Equal in String After Operations I [E]
// LeetCode check-if-digits-are-equal-in-string-after-operations-i

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string temp;
            for(int i = 1; i < s.size(); i ++) {
                temp += (s[i] + s[i - 1]) % 10 + '0';
            }
            // cout << temp << endl;
            s = temp;
        }
        // cout << s << endl;
        return s[0] == s[1];
    }
};