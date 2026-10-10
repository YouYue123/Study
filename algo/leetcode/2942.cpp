#include <bits/stdc++.h>
using namespace std;

// 2942. Find Words Containing Character [E]
// LeetCode find-words-containing-character

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i ++) {
            auto w = words[i];
            if(w.contains(x)) ans.push_back(i);
        }
        return ans;
    }
};