#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            int m = haystack.size(), n = needle.size();
            auto get_lps = [&] () {
                vector<int> lps(n, 0);
                for(int i = 1, match = 0; i < n; i ++) {
                    while(match > 0 && needle[i] != needle[match]) match = lps[match - 1];
                    if(needle[i] == needle[match]) match += 1;
                    lps[i] = match;
                }
                return lps;
            };
            auto lps = get_lps();
            for(int i = 0, j = 0; i < m; i ++) {
                while(j > 0 && haystack[i] != needle[j]) j = lps[j - 1];
                if(haystack[i] == needle[j]) j += 1;
                // cout << j << endl;
                if(j == n) {
                    // cout << i << endl;
                    return i - n + 1;
                }
            }
            return -1;
    }
};