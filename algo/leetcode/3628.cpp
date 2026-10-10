#include <bits/stdc++.h>
using namespace std;

// 3628. Maximum Number of Subsequences After One Inserting [M]
// LeetCode maximum-number-of-subsequences-after-one-inserting

class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        long long tCnt = 0;
        for(char c : s) if(c == 'T') tCnt += 1;
        long long lCnt = 0, cCnt = 0, lcCnt = 0, ltCnt = 0, ctCnt = 0, lctCnt = 0;
        for(char c : s) {
            if(c == 'L') {
                lCnt += 1;
            } else if(c == 'C') {
                cCnt += 1;
                lcCnt += lCnt;
            } else if(c == 'T') {
                tCnt -= 1;
                ctCnt += cCnt;
                lctCnt += lcCnt;
            }
            ltCnt = max(ltCnt, lCnt * tCnt);
        }
        return lctCnt + max({ lcCnt, ltCnt, ctCnt });
    }
};