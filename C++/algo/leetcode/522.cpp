#include <bits/stdc++.h>
using namespace std;

// 522. Longest Uncommon Subsequence II [M]
// LeetCode longest-uncommon-subsequence-ii

class Solution {
public:
    bool isSubsequence(string& s1, string& s2) {
        int i = 0, j =0;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) i += 1;
            j+= 1;
        }
        return i == s1.size();
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        for(int i = 0; i < n; i ++) {
            bool isSpecial = true;
            for(int j = 0; j < n; j ++) {
                if(i == j) continue;
                if(isSubsequence(strs[i], strs[j])) {
                    isSpecial = false;
                    break;
                }
            }
            if(isSpecial) ans = max(ans, (int)strs[i].size());
        }
        return ans;
    }
};