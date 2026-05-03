// 1541. Minimum Insertions to Balance a Parentheses String [M]
// LeetCode minimum-insertions-to-balance-a-parentheses-string

class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int leftCnt = 0;
        int index = 0;
        while(index < s.size()) {
            char c = s[index];
            if(c == '(') {
                index += 1;
                leftCnt += 1;
            } else {
                if(leftCnt > 0) {
                    if(index + 1 < s.size() && s[index + 1] == ')') {
                        index += 2;
                    } else {
                        ans += 1;
                        index += 1;
                    }
                    leftCnt -= 1;
                } else {
                    if(index + 1 < s.size() && s[index + 1] == ')') {
                        index += 2;
                        ans += 1;
                    } else {
                        ans += 2;
                        index += 1;
                    }
                }
            }
        }
        ans += leftCnt * 2;
        return ans;
    }
};