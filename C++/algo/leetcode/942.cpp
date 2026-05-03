// 942. DI String Match [E]
// LeetCode di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans(s.size() + 1, 0);
        int posI = 0;
        int posD = s.size();
        for(int i = 0 ; i < s.size(); ++i) {
            char c = s[i];
            if(c == 'I') {
                ans[i] = posI;
                posI += 1;
            } else {
                ans[i] = posD;
                posD -= 1;
            }
            // // cout << c << endl;
            // int add = c == 'I' ? 1 : -1;
            // // cout << add << endl;
            // ans[i + 1] = ans[i] + add;
        }
        ans[ans.size() - 1] = posI;
        return ans;
    }
};