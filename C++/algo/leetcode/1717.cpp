#include <bits/stdc++.h>
using namespace std;

// 1717. Maximum Score From Removing Substrings [M]
// LeetCode maximum-score-from-removing-substrings



class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        char first = (x > y) ? 'a' : 'b';
        char second = (x > y) ? 'b' : 'a';
        int first_priority = max(x, y);
        int second_priority = min(x, y);
        ans += removePairs(s, first, second, first_priority);
        ans += removePairs(s, second, first, second_priority);
        
        return ans;
    }
    int removePairs(string& s, char first_char, char second_char, int value) {
        stack<char> st;
        int res = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == first_char && c == second_char) {
                st.pop();
                res += value;
            } else {
                st.push(c);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return res;
    }
};