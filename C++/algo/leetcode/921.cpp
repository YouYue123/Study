// 921. Minimum Add to Make Parentheses Valid [M]
// LeetCode minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for(char c : s) {
            if(c == '(') {
                st.push(c);
            } else {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    ans += 1;
                }
            }
        }
        ans += st.size();
        return ans;
    }
};