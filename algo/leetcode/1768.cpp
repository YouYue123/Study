#include <bits/stdc++.h>
using namespace std;

// 1768. Merge Strings Alternately [E]
// LeetCode merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0;
        bool shouldP1 = true;
        string ans = "";
        while(p1 < word1.size() && p2 < word2.size()) {
            if(shouldP1) {
                ans.push_back(word1[p1]);
                p1 += 1;
                shouldP1 = false;
            } else{
                ans.push_back(word2[p2]);
                p2 += 1;
                shouldP1 = true;
            }
        }
        while(p1 < word1.size()) {
            ans.push_back(word1[p1]);
            p1 += 1;
        };
        while(p2 < word2.size()) {
            ans.push_back(word2[p2]);
            p2 += 1;
        }
        return ans;
    }
};