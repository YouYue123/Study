// 3582. Generate Tag for Video Caption [E]
// LeetCode generate-tag-for-video-caption

class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        int wCount = 0;
        char pre = ' ';
        for(char c : caption) {
            if(c == ' ') {
                if(pre != ' ') wCount += 1;
            } else {
                if(pre == ' ') {
                    if(wCount > 0) ans += toupper(c);
                    else ans += tolower(c);
                } else {
                    ans += tolower(c);
                }
            }
            if(ans.size() == 100) break;
            pre = c;
        }
        return ans;
    }
};