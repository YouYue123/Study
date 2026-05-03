#include <bits/stdc++.h>
using namespace std;

// 231. Power of Two [E]
// LeetCode power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (-n)) == n;
    }
};