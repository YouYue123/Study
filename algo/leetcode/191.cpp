#include <bits/stdc++.h>
using namespace std;

// 191. Number of 1 Bits [E]
// LeetCode number-of-1-bits

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n) {
            ans += 1;
            int lowBit = n & (-n);
            n = n ^ lowBit;
        }
        return ans;
    }
};