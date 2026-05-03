// 345. Reverse Vowels of a String [E]
// LeetCode reverse-vowels-of-a-string

class Solution {
public:
  // Return true if the character is a vowel (case-insensitive)
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
       int left = 0, right = s.size() - 1;
       while(left < right) {
        while(left < s.size() && !isVowel(s[left])) {
            left += 1;
        }
        while(right >= 0 && !isVowel(s[right])) {
            right -= 1;
        }
        if(left < right) {
            swap(s[left], s[right]);
            left += 1;
            right -= 1;
        }
       }  
       return s;
    }
};