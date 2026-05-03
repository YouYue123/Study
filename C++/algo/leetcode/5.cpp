// 5. Longest Palindromic Substring [M]
// LeetCode longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        int start = 0;
        auto check = [&] (int left, int right) {
            while(left >= 0 && right < n && s[left] == s[right]) {
                left -= 1;
                right += 1;
            }
            int len = (right - 1) - (left + 1) + 1;
            if(len > max_len) {
                max_len = len;
                start = left + 1;
            }
        };
        
        for(int i = 0; i < n; i ++) {
            check(i, i);
            check(i, i + 1);
        }
        return s.substr(start, max_len);
    }
};