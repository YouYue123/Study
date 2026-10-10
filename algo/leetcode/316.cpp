#include <bits/stdc++.h>
using namespace std;

// 316. Remove Duplicate Letters [M]
// LeetCode remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        unordered_map<char, int> cnt;
        for(char c : s) cnt[c] += 1;
        for(char c : s) {
            cnt[c] -= 1;
            if(ans.contains(c)) continue;
            if(ans.empty()) {
                ans.push_back(c);
            } else {
                // cout << "checking: " << c << endl;
                while(!ans.empty() && ans.back() > c && cnt[ans.back()] > 0) {
                    ans.pop_back();
                }   
                ans.push_back(c);
            }
        }
        return ans;
    }
};