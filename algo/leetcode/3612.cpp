#include <bits/stdc++.h>
using namespace std;

// 3612. Process String with Special Operations I [M]
// LeetCode process-string-with-special-operations-i

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(char c : s) {
            if(c == '*') {
                if(!ans.empty()) ans.pop_back();
            } else if(c == '#') {
                ans += ans;
            } else if(c == '%') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += c;
            }
        }
        return ans;
    }
};