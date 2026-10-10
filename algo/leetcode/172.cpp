#include <bits/stdc++.h>
using namespace std;

// 172. Factorial Trailing Zeroes [M]
// LeetCode factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int divisor = 5;
        while(n >= divisor) {
            ans += n / divisor;
            divisor *= 5;
        }
        return ans;
    }
};