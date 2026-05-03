#include <bits/stdc++.h>
using namespace std;

// 1784. Check if Binary String Has at Most One Segment of Ones [E]
// LeetCode check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        while(i < n) {
            if(s[i] == '1') {
                cnt += 1;
                while(i < n && s[i] == '1') i += 1;
            } else {
                i += 1;
            }
        }
        // cout << cnt << endl;
        return cnt <= 1;
    }
};