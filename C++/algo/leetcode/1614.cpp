// 1614. Maximum Nesting Depth of the Parentheses [E]
// LeetCode maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int leftCnt = 0;
        for(char c : s) {
            if(c == '(') {
                leftCnt += 1;
                ans = max(ans, leftCnt);
            } else if(c == ')') {
                leftCnt -= 1;
            }
        }
        return ans;
    }
};