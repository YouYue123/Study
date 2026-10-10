#include <bits/stdc++.h>
using namespace std;

// 3541. Find Most Frequent Vowel and Consonant [E]
// LeetCode find-most-frequent-vowel-and-consonant

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> dict;
        for(char c : s) dict[c] += 1;
        int vowelCount = 0;
        int constCount = 0;
        for(int i = 0; i < 26; i ++) {
            char curC = i + 'a';
            if(curC == 'a' || curC == 'e' || curC == 'i' || curC == 'o' || curC == 'u') {
                vowelCount = max(vowelCount, dict[curC]);
            } else {
                constCount = max(constCount, dict[curC]);
            }
        }
        return vowelCount + constCount;
    }
};