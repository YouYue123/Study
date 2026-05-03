#include <bits/stdc++.h>
using namespace std;

// 186. Reverse Words in a String II [M]
// LeetCode reverse-words-in-a-string-ii

class Solution {
public:
    void reverseWords(vector<char>& s) {
        std::reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        while(end <= s.size()) {
            // cout << "start: " << start<< " end: "<<end << endl;
            if(end == s.size() || s[end] == ' ') {
                std::reverse(s.begin()+start, s.begin() + end);
                end += 1;
                start = end;
            } else {
                end += 1;
            }
        }
    }
};