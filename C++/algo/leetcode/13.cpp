#include <bits/stdc++.h>
using namespace std;

// 13. Roman to Integer [E]
// LeetCode roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            { 'I', 1},
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        int i = 0;
        int ans = 0;
        while(i < s.length()) {
            int curVal = dict[s[i]];
            // cout << curVal << endl;
            if(i + 1 < s.length()) {
                int nextVal = dict[s[i+1]];
                // cout << "nextVal:" << nextVal << endl;
                if(curVal < nextVal) {
                    ans += nextVal - curVal;
                    i += 2;
                    continue;
                }
            }
            ans += curVal;
            i += 1;
            // cout << ans << endl;
        }
        return ans;
    }
};