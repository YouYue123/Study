#include <bits/stdc++.h>
using namespace std;

// 1048. Longest String Chain [M]
// LeetCode longest-string-chain

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dict;
        sort(words.begin(), words.end(), [&](auto& a, auto& b) {
            return a.size() < b.size();
        });
        int ans = 1;
        for(int i = 0; i < n; i ++) {
            string &b = words[i];
            dict[b] = 1;
            for(int j = 0; j < b.size(); j ++) {
                string prev = b.substr(0, j) + b.substr(j + 1);
                if(dict.contains(prev)) {
                    dict[b] = max(dict[b], dict[prev] + 1);
                    ans = max(ans, dict[b]);
                }
            }
         }
         return ans;
    }
};