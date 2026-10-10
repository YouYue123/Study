#include <bits/stdc++.h>
using namespace std;

// 3713. Longest Balanced Substring I [M]
// LeetCode longest-balanced-substring-i

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i < n; i ++) {
            int freq[26] = {0};
            for(int j = i ; j < n; j ++) {
                freq[s[j] - 'a'] += 1;
                int curFreq = -1;
                bool isValid = true;
                for(int k = 0; k < 26; k ++ ) {
                    if(freq[k] == 0) continue;
                    if(curFreq == -1) {
                        curFreq = freq[k];
                    } else {
                        if(curFreq != freq[k]) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if(isValid) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};