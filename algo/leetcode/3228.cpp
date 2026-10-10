#include <bits/stdc++.h>
using namespace std;

// 3228. Maximum Number of Operations to Move Ones to the End [M]
// LeetCode maximum-number-of-operations-to-move-ones-to-the-end

class Solution {
public:
    int maxOperations(string s) {
        int zeroCnt = s[s.size() - 1] == '0' ? 1 : 0;
        int ans = 0;
        for(int i = s.size() - 2; i >=0 ; i --) {
            if(s[i] == '0' && s[i + 1] != '0') zeroCnt += 1;
            if(s[i] == '1') ans += zeroCnt;
            // cout << i << " " << zeroCnt << endl;
        }
        return ans;
    }
};