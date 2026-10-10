#include <bits/stdc++.h>
using namespace std;

// 69. Sqrt(x) [E]
// LeetCode sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int left = 2, right = x / 2 + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            long long num = (long long) mid * mid;
            if(num >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return long(left) * left == x ? left : left - 1;
    }
};