#include <bits/stdc++.h>
using namespace std;

// 1408. String Matching in an Array [E]
// LeetCode string-matching-in-an-array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i ++) {
            for (int j = 0; j < words.size(); j ++) {
                if (i == j) {
                    continue;
                }
                if(isSubStr(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
    // if sub is a substring of main
    bool isSubStr(string& sub, string& main) {
        for (int i = 0; i < main.size(); i ++) {
            bool find = true;
            for(int j = 0; j < sub.size(); j ++) {
                if(i + j >= main.size() || main[i+j] != sub[j]) {
                    find = false;
                    break;
                }
            }
            if(find) {
                return true;
            }
        }
        return false;
    }
};