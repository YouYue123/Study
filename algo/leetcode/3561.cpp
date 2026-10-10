#include <bits/stdc++.h>
using namespace std;

// 3561. Resulting String After Adjacent Removals [M]
// LeetCode resulting-string-after-adjacent-removals

class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(char c : s) {
            // cout << c << endl; 
            if(!st.empty()) {
                char next = ((c - 'a') + 1) % 26 + 'a';
                char prev = (((c - 'a') - 1) % 26 + 26) % 26 + 'a';
                // cout << next << " " << prev << endl;
                if(st.top() == next || st.top() == prev) {
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