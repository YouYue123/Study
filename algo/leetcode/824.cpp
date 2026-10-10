#include <bits/stdc++.h>
using namespace std;

// 824. Goat Latin [E]
// LeetCode goat-latin

class Solution {
public:
    string toGoatLatin(string sentence) {
        auto w_list = views::split(sentence, ' ');
        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u'
        };
        string ans = "";
        int idx = 1;
        for(auto w : w_list) {
            if(w.empty()) continue;
            if(!ans.empty()) ans += ' ';
            string word(w.begin(), w.end());
            if(vowels.contains(tolower(w[0]))) {
                ans += word + "ma";
            } else {
                ans += word.substr(1) + word[0] +  "ma";
            }
            for(int j = 0; j < idx; j ++) ans += 'a';
            idx += 1;
        }
        return ans;
    }
};