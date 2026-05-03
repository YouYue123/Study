#include <bits/stdc++.h>
using namespace std;

// 1461. Check If a String Contains All Binary Codes of Size K [M]
// LeetCode check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int curVal = 0;
        unordered_map<int, bool> dict;
        int pow = 1;
        for(int i = 0; i < n; i ++) {
            curVal += (s[i] - '0') * pow;
            if(i < k - 1) {
                pow *= 2;
            } else {
                if(!dict[curVal]) dict[curVal] = true;
                curVal /= 2;
            }
        }
        return dict.size() == std::pow(2, k);
    }
};