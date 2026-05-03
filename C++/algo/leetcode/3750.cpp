#include <bits/stdc++.h>
using namespace std;

// 3750. Minimum Number of Flips to Reverse Binary String [E]
// LeetCode minimum-number-of-flips-to-reverse-binary-string

class Solution {
public:
    int minimumFlips(int n) {
        uint32_t num = n;
        uint32_t rev = __builtin_bitreverse32(n) >> countl_zero(num);
        return popcount(n ^ rev);
    }
};