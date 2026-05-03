// 1544. Make The String Great [E]
// LeetCode make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c : s) {
            if(c >= 'A' && c <= 'Z') {
                if(!st.empty() && st.top() == tolower(c)) {
                    st.pop();
                    continue;
                }
            } else {
                if(!st.empty() && st.top() == toupper(c)) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};