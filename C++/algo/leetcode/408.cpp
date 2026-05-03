#include <bits/stdc++.h>
using namespace std;

// 408. Valid Word Abbreviation [E]
// LeetCode valid-word-abbreviation

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
         int m = word.size(), n = abbr.size();
         int p1 = 0, p2 = 0;
         bool is_prev_num = false;
         while(p1 < m && p2 < n) {
            if(isdigit(abbr[p2])) {
                if(abbr[p2] == '0') return false; 
                if(is_prev_num) return false;
                is_prev_num = true;
                int num = 0;
                while(p2 < n && isdigit(abbr[p2])) {
                    num = num * 10 + (abbr[p2] - '0');
                    p2 += 1;
                }
                p1 += num;
            } else {
                is_prev_num = false;
                if(word[p1] != abbr[p2]) return false;
                p1 += 1;
                p2 += 1;
            }
         }
         return p1 == m && p2 == n;
    }
};