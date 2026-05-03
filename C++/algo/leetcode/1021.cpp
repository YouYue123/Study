// 1021. Remove Outermost Parentheses [E]
// LeetCode remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string temp = "";
        string ans = "";
        for(char c : s) {
            if(c == ')') {
                st.pop();
                if(st.empty()) {
                    ans += temp.substr(1);
                    temp = "";
                } else {
                    temp += c;
                }
            } else {
                temp += c;
                st.push(c);
            }
        }
        return ans;
    }
};