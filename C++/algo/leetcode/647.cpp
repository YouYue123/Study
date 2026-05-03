// 647. Palindromic Substrings [M]
// LeetCode palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        auto expand = [&] (int i, int j) {
            while(i >= 0 && j < n && s[i] == s[j]) {
                ans += 1;
                i -= 1;
                j += 1;
            }
        };
        for(int i = 0; i < n; i ++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return ans;
    }
};