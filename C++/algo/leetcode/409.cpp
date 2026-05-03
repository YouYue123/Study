// 409. Longest Palindrome [E]
// LeetCode longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c] += 1;
        int ans = 0;
        bool hasOddFreq = false;
        for(auto& p : freq) {
            if(p.second % 2 == 0) {
                ans += p.second;
            } else {
                ans += p.second - 1;
                hasOddFreq = true;
            }
        }
        if(hasOddFreq) return ans + 1;
        return ans;
    }
};