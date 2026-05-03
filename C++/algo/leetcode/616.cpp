#include <bits/stdc++.h>
using namespace std;

// 616. Add Bold Tag in String [M]
// LeetCode add-bold-tag-in-string

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.length();
        
        string ans = "";
        vector<bool> bold(n);
        for (string& word: words) {
            int start = s.find(word);
            // cout << word << " "<<start << endl;
            while(start != string::npos) {
                for(int i = start; i < start + word.size() ; i ++)  bold[i] = true;
                start = s.find(word, start + 1);
            }
        }
        string openTag = "<b>";
        string closeTag = "</b>";
        for (int i =0; i < s.size(); i ++) {
            // cout << "i: " << i << "bold: " << bold[i] << endl;
            if (bold[i] && (i == 0 || !bold[i - 1])) {
                ans += openTag;
            }

            ans += s[i];

            if(bold[i] && (i == n - 1 || !bold[i + 1])) {
                ans += closeTag;
            }
        }
        return ans;
    }
};