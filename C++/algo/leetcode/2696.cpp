#include <bits/stdc++.h>
using namespace std;

// 2696. Minimum String Length After Removing Substrings [E]
// LeetCode minimum-string-length-after-removing-substrings

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == 'D') {
                if(!st.empty() && st.top() == 'C') {
                    st.pop();
                    continue;
                }
            } else if(c == 'B') {
                // cout << st.top() <<endl;
                if(!st.empty() && st.top() == 'A') {
                    st.pop();
                    continue;
                }
            }
             st.push(c);
            // cout << st.size() << endl;
        }
        return st.size();
    }
};