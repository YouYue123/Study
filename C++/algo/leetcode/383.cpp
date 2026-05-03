#include <bits/stdc++.h>
using namespace std;

// 383. Ransom Note [E]
// LeetCode ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for(char c : magazine) dict[c] += 1;
        for(char c : ransomNote) {
            if(!dict.contains(c)) return false;
            dict[c] -= 1;
            if(dict[c] < 0) return false;
        }
        return true;
    }
};