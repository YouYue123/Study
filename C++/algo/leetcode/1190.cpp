#include <bits/stdc++.h>
using namespace std;

// 1190. Reverse Substrings Between Each Pair of Parentheses [M]
// LeetCode reverse-substrings-between-each-pair-of-parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for(char c : s) {
            if(c == ')') {
                string temp = "";
                // cout << st.size() << endl;
                while(st.top() != "(") {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                st.push(temp);
            } else {
                // cout << c + " " << endl;
                st.push(string(1, c));
            }
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