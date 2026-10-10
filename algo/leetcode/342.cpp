#include <bits/stdc++.h>
using namespace std;

// 342. Power of Four [E]
// LeetCode power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        // positive && 2^k && 1 exist in odd pos
        return n > 0 && (n & (n - 1)) == 0 && (n % 3) == 1;
    }
};