#include <bits/stdc++.h>
using namespace std;

// 3597. Partition String  [M]
// LeetCode partition-string

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> dict;
        string temp = "";
        vector<string> ans;
        for(char c : s) {
            temp += c;
            if(!dict.contains(temp)) {
                ans.push_back(temp);
                dict.insert(temp);
                temp = "";
            }
        }
        return ans;
    }
};