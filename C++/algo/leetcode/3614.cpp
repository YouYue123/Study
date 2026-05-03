#include <bits/stdc++.h>
using namespace std;

// 3614. Process String with Special Operations II [H]
// LeetCode process-string-with-special-operations-ii

class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> lens(s.size());
        long long curLen = 0;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if(c >= 'a' && c <= 'z') {
                curLen += 1;
            } else if(c == '*') {
                curLen = max(0LL, curLen - 1);
            } else if(c == '#') {
                curLen *= 2;
            }
            lens[i] = curLen;
        }
        long long finalLen = lens.empty() ? 0 : lens.back();
        if(k >= finalLen) return '.';
        for (int i = s.size() - 1; i >= 0; i --)  {
            char c = s[i];
            long long lenBefore = (i > 0) ? lens[i - 1] : 0;
            if (c == '#') {
                if(lenBefore > 0) k %= lenBefore;
            } else if(c == '%') {
                k = lenBefore - 1 - k;
            } else if(c >= 'a' && c <= 'z') {
                if(k == lenBefore) return c;
            }
        }
        return '.';
    }
};