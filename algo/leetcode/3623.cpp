#include <bits/stdc++.h>
using namespace std;

// 3623. Count Number of Trapezoids I [M]
// LeetCode count-number-of-trapezoids-i

int MOD = 1e9 + 7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> dict;
        for(auto& p : points) dict[p[1]] += 1;
        long long presum = 0;
        long long ans = 0;
        for(auto &&[x, cnt] : dict) {
            long long cur = (long long)cnt * (cnt - 1) / 2 % MOD;
            ans = (ans + cur * presum % MOD) % MOD;
            presum = (presum + cur) % MOD;
        }
        return ans;
    }
};