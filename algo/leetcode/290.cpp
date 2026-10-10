#include <bits/stdc++.h>
using namespace std;

// 290. Word Pattern [E]
// LeetCode word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> dict;
        unordered_map<string, char> reverseDict;
        int p1 = 0, p2 = 0;
        while(p1 < pattern.size() && p2 < s.size()) {
            char c = pattern[p1];
            string temp = "";
            while(p2 < s.size() && s[p2] != ' ') {
                temp += s[p2];
                p2 += 1;
            }
            // cout << c << " " << temp << endl;
            if(dict.contains(c) || reverseDict[temp]) {
                if(!dict.contains(c) || !reverseDict.contains(temp)) return false;
                if(dict[c] != temp || reverseDict[temp] != c) return false;
            }
            dict[c] = temp;
            reverseDict[temp] = c;
            p1 += 1;
            if(p2 < s.size()) p2 += 1;
        }
        // cout << p1 << " " << p2 << endl;
        // cout << pattern.size() << " " << s.size() << endl;
        return p1 == pattern.size() && p2 == s.size();
    }
};