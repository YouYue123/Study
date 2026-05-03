#include <bits/stdc++.h>
using namespace std;

// 1657. Determine if Two Strings Are Close [M]
// LeetCode determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> w1Dict(26, 0);
        vector<int> w2Dict(26, 0);
        for(char c : word1) w1Dict[c - 'a'] += 1;
        for(char c : word2) w2Dict[c - 'a'] += 1;
        for(int i = 0; i < 26; i ++) {
            if(w1Dict[i] == 0 && w2Dict[i] > 0) return false;
            if(w2Dict[i] == 0 && w1Dict[i] > 0) return false;
        }
        sort(w1Dict.begin(), w1Dict.end());
        sort(w2Dict.begin(), w2Dict.end());
        return w1Dict == w2Dict;
    }
};