#include <bits/stdc++.h>
using namespace std;

// 1957. Delete Characters to Make Fancy String [E]
// LeetCode delete-characters-to-make-fancy-string

class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1;
        char pre = ' ';
        string ans = "";
        for(char c : s) {
            if(c == pre) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if(cnt < 3) ans += c;
            pre = c;
        }
        return ans;
    }
};