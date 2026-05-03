// 3517. Smallest Palindromic Rearrangement I [M]
// LeetCode smallest-palindromic-rearrangement-i

class Solution {
public:
    string smallestPalindrome(string s) {
        string pre = "";
        string mid = "";
        string post = "";
        int dict[26];
        for(char c : s) dict[c - 'a'] += 1;
        for(int i = 0; i < 26; i ++) {
            if(dict[i] >= 2) {
                int count = dict[i] / 2;
                string fix = string(count, i + 'a');
                pre = pre + fix ;
                post = fix + post ;
            }
            if(dict[i] % 2 == 1) {
                mid += string(1,i + 'a');
            } 
        }
        // cout << "pre: " << pre << endl;
        // cout << "mid: " << mid << endl;
        // cout << "post: " << post << endl;
        return pre + mid + post;
    }
};