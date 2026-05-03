#include <bits/stdc++.h>
using namespace std;

// 844. Backspace String Compare [E]
// LeetCode backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st, tt;
        auto calc = [] (stack<char>& stack, string& str) {
            for(char c : str) {
                if(c == '#') {
                    if(!stack.empty()) stack.pop();
                } else {
                    stack.push(c);
                }
            }
            string ans = "";
            while(!stack.empty()) {
                ans += stack.top();
                stack.pop();
            }
            return ans;
        };
        return calc(st, s) == calc(tt, t);
    }
};