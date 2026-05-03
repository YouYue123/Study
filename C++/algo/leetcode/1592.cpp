#include <bits/stdc++.h>
using namespace std;

// 1592. Rearrange Spaces Between Words [E]
// LeetCode rearrange-spaces-between-words

class Solution {
public:
    string reorderSpaces(string text) {
        int spaceCount = 0;
        vector<string> words;
        int i = 0;
        while(i < text.size()) {
            if(text[i] == ' ') {
                spaceCount += 1;
                i += 1;
            } else {
                string temp = "";
                while(i < text.size() && text[i] != ' ') {
                    temp += text[i];
                    i += 1;
                }
                words.push_back(temp);
            }
        }
        string ans = "";
        if(words.size() == 1) {
            ans += words[0];
            for(int i = 0; i < spaceCount; i ++) ans += " ";
            return ans;
        }
        int gap = words.size() - 1;
        int space = spaceCount / gap;
        int extraSpace = spaceCount % gap;
        for(int i = 0; i < words.size(); i ++) {
            ans += words[i];
            if(i != words.size() - 1) {
                for(int j = 0; j < space; j ++) {
                    ans += " ";
                }
            }
        }
        for(int i = 0; i < extraSpace; i ++) {
            ans += " ";
        }
        return ans;
    }
};