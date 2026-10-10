#include <bits/stdc++.h>
using namespace std;

// 3560. Find Minimum Log Transportation Cost [E]
// LeetCode find-minimum-log-transportation-cost

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n <= k && m <= k) return 0;
        if(n > k) {
            return (long long)(n - k) * k;
        } else{
            return (long long)(m - k) * k;
        }
    }
};