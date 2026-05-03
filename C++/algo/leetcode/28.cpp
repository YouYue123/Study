#include <bits/stdc++.h>
using namespace std;

// 28. Find the Index of the First Occurrence in a String [E]
// LeetCode find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> next(m, 0);
        for(int i = 1, j = 0; i < m ; i ++) {
            while(j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if(needle[i] == needle[j]) j += 1;
            next[i] = j;
        }
        for(int i = 0, j = 0; i < n; i ++) {
            while(j > 0 && haystack[i] != needle[j] ) {
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]) j += 1;
            if(j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};