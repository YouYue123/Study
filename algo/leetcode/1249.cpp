#include <bits/stdc++.h>
using namespace std;

// 1249. Minimum Remove to Make Valid Parentheses [M]
// LeetCode minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int open_cnt = 0;
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(c == '(') {
                open_cnt += 1;
            } else if (c == ')') {
                if(open_cnt == 0) continue;
                open_cnt -= 1;
                s[i] = '$';
            }
        }
        int close_cnt = 0;
        for(int i = n - 1; i >= 0; i --) {
            char c = s[i];
            if(c == '$') {
                close_cnt += 1;
            } else if(c == '(') {
                if(close_cnt == 0) continue;
                close_cnt -= 1;
                s[i] = '#';
            }
        }
        // stack<int> st;
        // for(int i = 0; i < n; i ++) {
        //     char c = s[i];
        //     if(c == '(') {
        //         st.push(i);
        //     } else if(c == ')') {
        //         if(st.empty()) continue;
        //         s[st.top()] ='#';
        //         st.pop();
        //         s[i] = '$';
        //     }
        // }
        string ans = "";
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(c == '#' ) {
                ans += '(';
            } else if(c == '$') {
                ans += ')';
            } else if(c != '(' && c != ')' ){
                ans += s[i];
            }
        }
        // cout << s << endl;
        return ans;
    }
};