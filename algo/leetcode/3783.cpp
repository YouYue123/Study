#include <bits/stdc++.h>
using namespace std;

// 3783. Mirror Distance of an Integer [E]
// LeetCode mirror-distance-of-an-integer

class Solution {
public:
    int mirrorDistance(int n) {
        auto reverse = [&] (int num) {
            int ans = 0;
            while(num > 0) {
                ans = ans * 10 + num % 10;
                num /= 10;
            }
            return ans;
        };
        return abs(n - reverse(n));
    }
};