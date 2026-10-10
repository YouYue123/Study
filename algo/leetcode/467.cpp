#include <bits/stdc++.h>
using namespace std;

// 467. Unique Substrings in Wraparound String [M]
// LeetCode unique-substrings-in-wraparound-string

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector maxLens(26, 0);
        int maxLen = 0;
        for(int i = 0; i < n; i ++) {
            if(i > 0 && ((s[i] + 26) - s[i - 1]) % 26  == 1) maxLen += 1;
            else maxLen = 1;
            maxLens[s[i] - 'a'] = max(maxLens[s[i] - 'a'], maxLen);
        }
        return accumulate(maxLens.begin(), maxLens.end(), 0);
    }
};