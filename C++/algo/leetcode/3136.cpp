#include <bits/stdc++.h>
using namespace std;

// 3136. Valid Word [E]
// LeetCode valid-word

class Solution {
public:
    bool isValid(string word) {
        unordered_set vowels = { 'a', 'e', 'i', 'o', 'u'};
        bool hasVowel = false;
        bool hasConsonant = false;
        for(char c : word) {
            if(!isalnum(c)) return false;
            if(vowels.contains(tolower(c))) hasVowel = true;
            if(isalpha(c) && !vowels.contains(tolower(c))) hasConsonant = true;
        }
        return word.size() >= 3 && hasVowel && hasConsonant;
    }
};