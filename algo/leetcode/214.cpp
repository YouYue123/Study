#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string shortestPalindrome(string s) {
            // S = A + B
            // A is the longest palindrome prefix
            // ans = rev(B) + A + B
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            string comb_s = s + "#" + rev_s;

            auto get_lps = [&] () {
                int n = comb_s.size();
                vector<int> lps(n, 0);
                for(int i = 1, match = 0; i < n; i ++) {
                    while(match > 0 && comb_s[i] != comb_s[match]) match = lps[match - 1];
                    if(comb_s[i] == comb_s[match]) match += 1;
                    lps[i] = match;
                }
                return lps;
            };

            int len = get_lps().back();
            // cout << len << endl;
            string B = s.substr(len);
            reverse(B.begin(), B.end());
            return B + s;
        }
};