// 58. Length of Last Word [E]
// LeetCode length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = 0, end = 0;
        bool inWord = false;
        int ans = 0;
        for(int i = 0; i < s.length(); i ++) {
            if(isalpha(s[i])) {
                if(inWord) {
                    end = i;
                } else {
                    inWord = true;
                    start = i;
                    end = i;
                }
            } else {
                inWord = false;
            }
        }
        return end - start + 1;
    }
};