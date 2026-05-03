// 520. Detect Capital [E]
// LeetCode detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int capCnt = 0;
        int smallCnt = 0;
        int isFirstCap = false;
        auto isCap = [&] (char c) {
            return c >= 'A' && c <= 'Z';
        };
        for(int i = 0; i < n; i ++) {
            if(isCap(word[i])) {
                if(i == 0) {
                    isFirstCap = true;  
                }
                capCnt += 1;
            } else {
                smallCnt += 1;
            }
        }
        return capCnt == n || smallCnt == n || (isFirstCap && capCnt == 1);
    }
};