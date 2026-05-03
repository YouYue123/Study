#include <bits/stdc++.h>
using namespace std;

// 242. Valid Anagram [E]
// LeetCode valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> dict;
        for(char c : s) {
            dict[c] += 1;
        }
        for(char c : t) {
            if(!dict.contains(c)) return false;
            dict[c] -= 1;
            if(dict[c] == 0) dict.erase(c);
        }
        return dict.empty();
    }
};