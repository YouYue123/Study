#include <bits/stdc++.h>
using namespace std;

// 3330. Find the Original Typed String I [E]
// LeetCode find-the-original-typed-string-i

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0;
        char prev = ' ';
        int cnt = 0;
        for(char c : word) {
            if(c != prev) {
                ans += max(cnt - 1,  0);
                cnt = 0;
            }
            cnt += 1;
            prev = c;
        }
        ans += max(cnt - 1, 0);
        ans += 1;
        return ans;
    }
};