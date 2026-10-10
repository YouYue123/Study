#include <bits/stdc++.h>
using namespace std;

// 2138. Divide a String Into Groups of Size k [E]
// LeetCode divide-a-string-into-groups-of-size-k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < s.size(); i ++) {
            temp += s[i];
            if(temp.size() % k == 0) {
                ans.push_back(temp);
                temp = "";
            }
        }
        if(!temp.empty()) {
            while(temp.size() < k) {
                temp += fill;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};