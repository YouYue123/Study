#include <bits/stdc++.h>
using namespace std;

// 482. License Key Formatting [E]
// LeetCode license-key-formatting

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        string ans = "";
        int cnt = 0;
        string curGroup = "";
        auto addGroup = [&] (string& group) {
            if(!ans.empty()) ans += '-';
            ans += curGroup;
        };
        for(int i = n - 1; i >= 0; i --) {
            if(s[i] == '-') continue;
            curGroup += isalpha(s[i]) ? toupper(s[i]) : s[i];
            if(curGroup.size() == k) {
                addGroup(curGroup);
                curGroup = "";
            }
        }
        if(!curGroup.empty()) addGroup(curGroup);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};