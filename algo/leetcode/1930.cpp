#include <bits/stdc++.h>
using namespace std;

// 1930. Unique Length-3 Palindromic Subsequences [M]
// LeetCode unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> posDict;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            posDict[c].push_back(i);
        }
        
        int ans = 0;
        for(int i = 0; i < 26; i ++) {
            char curC = 'a' + i;
            if(posDict[curC].size() < 2) continue; 
            int cnt = 0;
            unordered_set<char> set;
            for(int j = 0; j < s.size(); j ++) {
                char c = s[j];
                if(j > posDict[curC].front() && j < posDict[curC].back()) set.insert(c);
            }
            ans += set.size();
            // cout << curC << " : " << ans << endl;
            // for(auto a: dict[curC]) cout <<  a << " ";
            // cout << endl;
        }
        return ans;
    }
};