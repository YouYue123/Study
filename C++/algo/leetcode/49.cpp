#include <bits/stdc++.h>
using namespace std;

// 49. Group Anagrams [M]
// LeetCode group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> dict;
        for(string& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(str);
        }
        for(auto& [_, val] : dict) {
            ans.push_back(val);
        }
        return ans;
    }
};