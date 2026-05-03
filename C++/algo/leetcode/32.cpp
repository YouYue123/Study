// 32. Longest Valid Parentheses [H]
// LeetCode longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(c == '(') {
                st.push(i);
            } else {
                if(st.size() > 1) {
                    st.pop();
                    ans = max(ans, i - st.top());
                } else {
                    st.top() = i;
                }
            }
        }
        return ans;
    }
};