#include <bits/stdc++.h>
using namespace std;

// 440. K-th Smallest in Lexicographical Order [H]
// LeetCode k-th-smallest-in-lexicographical-order

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1;
        auto calc_step = [&] (long long n1, long long n2) -> int {
            int ans = 0;
            while(n1 <= n) {
                ans += min(n + 1LL, n2) - n1;
                n1 *= 10;
                n2 *= 10;
            }
            return ans;
        };
        while(k > 0) {
            int step = calc_step(cur, cur + 1);
            // cout << cur << " " << cur + 1 << endl;
            // cout << "step: " << step << endl;
            if(step <= k) {
                cur += 1;
                k -= step;
            } else {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
};