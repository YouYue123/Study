// 2264. Largest 3-Same-Digit Number in String [E]
// LeetCode largest-3-same-digit-number-in-string

class Solution {
public:
    string largestGoodInteger(string num) {
        if(num.size() == 0) return "";
        string ans = "";
        char pre = ' ';
        int cnt = 0;
        for(int i = 0; i < num.size(); i ++) {
            char cur = num[i];
            if(pre == cur) cnt += 1;
            else {
                // cout << cnt << endl;
                if(cnt >= 3) {
                    string temp = "";
                    for(int i = 0; i < 3; i ++) temp += pre;
                    ans = max(ans, temp);
                }
                cnt = 1;
            }
            pre = cur;
        }
        if(cnt >= 3) {
            string temp = "";
            for(int i = 0; i < 3; i ++) temp += pre;
            ans = max(ans, temp);
        }
        return ans;
    }
};