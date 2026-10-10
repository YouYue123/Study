#include <bits/stdc++.h>
using namespace std;

// 2559. Count Vowel Strings in Ranges [M]
// LeetCode count-vowel-strings-in-ranges

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> preSum(words.size() + 1, 0);
        unordered_set<char> set = {
            'a', 'e', 'i', 'o', 'u'
        }; 
        for(int i = 1; i <= words.size(); i ++) {
            string& w = words[i - 1];
            preSum[i] = preSum[i - 1];
            if(set.contains(w.front()) && set.contains(w.back())) {
                preSum[i] += 1;
            }
        }
        // for(int i = 0; i < words)
        vector<int> ans;
        for(const vector<int>& q : queries) {
            ans.push_back(preSum[q[1] + 1] - preSum[q[0]]);
        }
        return ans;
    }
};