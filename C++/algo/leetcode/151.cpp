#include <bits/stdc++.h>
using namespace std;

// 151. Reverse Words in a String [M]
// LeetCode reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        for(char c: s) {
            if(c == ' ') {
                if(!ss.str().empty() && ss.str().back() != ' ') {
                    ss << c;
                }
            } else {
                ss << c;
            }
        }
        string cleanS = ss.str();
        if(cleanS.back() == ' ') cleanS.pop_back();
        reverse(cleanS.begin(), cleanS.end());
        int lastStart = 0;
        for(int i =0; i < cleanS.size(); i ++) {
            if(cleanS[i] == ' ') {
                reverse(cleanS.begin() + lastStart, cleanS.begin() + i);
                lastStart = i + 1;
            }
        }
        reverse(cleanS.begin() + lastStart, cleanS.end());
        return cleanS;
    }
};