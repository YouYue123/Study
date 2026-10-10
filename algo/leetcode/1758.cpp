#include <bits/stdc++.h>
using namespace std;

// 1758. Minimum Changes To Make Alternating Binary String [E]
// LeetCode minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        // int ans = 0;
        int curAns = 0;
        char cur = '0';
        for(char c : s) {
            if(c != cur) curAns += 1;
            cur = (cur == '0' ? '1' : '0');
        }
        // ans = curAns;
        // cur = '1';
        // curAns = 0;
        // for(char c : s) {
        //     if(c != cur) curAns += 1;
        //     cur = (cur == '0' ? '1' : '0');
        // }
        // ans = min(ans, curAns);
        return min(n - curAns, curAns);
    }
};