#include <bits/stdc++.h>
using namespace std;

// 50. Pow(x, n) [M]
// LeetCode powx-n

class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1.0;
        bool is_neg = n < 0;
        n = abs(n);
        double base = x;
        double ans = 1.0;
        while(n > 0) {
            if(n & 1) {
                ans = ans * base;
                n -= 1;
            }
            base = base * base;
            n /= 2;
        }
        return is_neg ? 1.0 / ans : ans;
    }
};