#include <bits/stdc++.h>
using namespace std;

// 1979. Find Greatest Common Divisor of Array [E]
// LeetCode find-greatest-common-divisor-of-array

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        if(a < b) return gcd(b, a);
        return gcd(b, a - b);
    }
    int findGCD(vector<int>& nums) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for(int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        return gcd(maxVal, minVal);
    }
};