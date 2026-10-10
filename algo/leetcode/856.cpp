#include <bits/stdc++.h>
using namespace std;

// 856. Score of Parentheses [M]
// LeetCode score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        int leftCnt = 0;
        int ans = 0;
        char prev = ' ';
        for(char c : s) {
            if(c == '(') {
                leftCnt += 1;
            } else {
                leftCnt -= 1;
                if(prev == '(') ans += pow(2, leftCnt);
            }
            prev = c;
        }
        return ans;
    }
};