#include <bits/stdc++.h>
using namespace std;

// 443. String Compression [M]
// LeetCode string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ans = 0;
        while(i < chars.size()) {
            int groupLen = 1;
            while(i + groupLen < chars.size() && chars[i] == chars[i + groupLen]) {
                groupLen += 1;
            }
            chars[ans] = chars[i];
            ans += 1;
            if(groupLen > 1) {
                for(char c: to_string(groupLen)) {
                    chars[ans] = c;
                    ans += 1;
                }
            }
           
            i += groupLen;
        }
        return ans;
    }
};