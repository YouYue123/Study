// 1963. Minimum Number of Swaps to Make the String Balanced [M]
// LeetCode minimum-number-of-swaps-to-make-the-string-balanced

class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int leftCnt = 0;
        for(char c : s) {
            if(c == ']') {
                if(leftCnt == 0) {
                    ans += 1;
                } else {
                    leftCnt -= 1;
                }
            } else {
                leftCnt += 1;
            }
        }
        return (ans + 1) / 2;
    }
};