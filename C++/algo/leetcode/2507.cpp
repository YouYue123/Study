#include <bits/stdc++.h>
using namespace std;

// 2507. Smallest Value After Replacing With Sum of Prime Factors [M]
// LeetCode smallest-value-after-replacing-with-sum-of-prime-factors

class Solution {
public:
    int smallestValue(int n) {
        auto get_prime_factors_sum = [&] (int x) {
            int ans = 0;
            for(int p = 2; p * p <= x; p += 1) {
                while(x % p == 0) {
                    ans += p;
                    x /= p;
                }
            }
            if(x > 1) ans += x;
            return ans;
        };
        while (true) {
            int next_val = get_prime_factors_sum(n);
            if (next_val == n) break;
            n = next_val;
        }
        return n;
    }
};