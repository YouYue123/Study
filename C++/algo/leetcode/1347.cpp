// 1347. Minimum Number of Steps to Make Two Strings Anagram [M]
// LeetCode minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
       // s: bab 1a 2b
       // t: aba 2a 1b
       // ans: 2 
       // s: leetcode 0a 1c 1d 3e 0p 0r 1t 0i 1l 1o
       // t: practice 1a 2c 0d 1e 1p 1r 1t 1i 0l 0o
       // ans: 1 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + = 10
       unordered_map<int, int> dictS;
       unordered_map<int, int> dictT;
       for(char c : s) dictS[c] += 1;
       for(char c : t) dictT[c] += 1;
       int ans = 0;
       for(int i = 0; i < 26 ; i ++) {
            ans += abs(dictS[i + 'a'] - dictT[i + 'a']);
       }
       return ans / 2;
    }
};