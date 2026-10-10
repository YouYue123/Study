#include <bits/stdc++.h>
using namespace std;

// 249. Group Shifted Strings [M]
// LeetCode group-shifted-strings

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        auto hash = [&] (string& s) {
            string ans = "";
            for(int i = 1; i < s.size(); i ++) {
                ans += to_string((s[i] - s[i - 1] + 26) % 26);
                ans += ',';
            }
            return ans;
        };
        unordered_map<string, vector<string>> dict;
        for(auto& s : strings) {
            dict[hash(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [_, items] : dict) {
            ans.push_back(items);
        }
        return ans;
    }
};