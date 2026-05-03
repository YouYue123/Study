// 20. Valid Parentheses [E]
// LeetCode valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        auto is_open = [&] (char c) {
            return c == '(' || c == '[' || c == '{';
        };
        auto is_match = [&] (char open, char close) {
            if(open == '(') return close == ')';
            if(open == '[') return close == ']';
            if(open == '{') return close == '}';
            return false;
        };
        for(char c : s) {
            if(is_open(c)) {
                st.push(c);
            } else {
                if(st.empty()) return false;
                if(!is_match(st.top(), c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};