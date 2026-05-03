#include <bits/stdc++.h>
using namespace std;

// 1653. Minimum Deletions to Make String Balanced [M]
// LeetCode minimum-deletions-to-make-string-balanced

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int aRight = 0;
        for(char c : s) if(c == 'a') aRight += 1;
        int bLeft = 0;
        int ans = aRight;
        for(char c : s) {
            if(c == 'a') {
                aRight -= 1;
            } else {
                bLeft += 1;
            }
            ans = min(ans, aRight + bLeft);
        }
        return ans;
    }
};