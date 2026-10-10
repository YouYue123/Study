#include <bits/stdc++.h>
using namespace std;

// 761. Special Binary String [H]
// LeetCode special-binary-string

class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        if(n <= 2) return s;
        vector<string> substr;
        int diff = 0;
        int start = 0;
        for(int i = 0; i < n; i ++) {
            if(s[i] == '1') {
                diff += 1;
            } else {
                diff -= 1;
            }
            if(diff == 0) {
                substr.push_back(
                    "1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) +"0"
                );
                start = i + 1;
            }
        }
        // cout << substr.size() << endl;
        sort(substr.begin(), substr.end(), greater<>());
        string ans = "";
        for(string& str : substr) ans += str;
        return ans;
    }
};