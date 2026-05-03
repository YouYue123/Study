#include <bits/stdc++.h>
using namespace std;

// 693. Binary Number with Alternating Bits [E]
// LeetCode binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n = n >> 1;
        while(n > 0) {
            int cur = n & 1;
            // cout << prev << " " << cur << endl;
            if(cur == prev) return false;
            prev = cur;
            n = n >> 1;
        }
        return true;
    }
};