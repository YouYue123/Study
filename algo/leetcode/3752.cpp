#include <bits/stdc++.h>
using namespace std;

// 3752. Lexicographically Smallest Negated Permutation that Sums to Target [M]
// LeetCode lexicographically-smallest-negated-permutation-that-sums-to-target

class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long s = 1LL * n * (n + 1) / 2;
        if(s < abs(target) || (s - target) % 2 == 1) return {};
        long long neg = (s - target) / 2;
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for(int x = n; x >= 1; --x) {
            if(neg >= x) {
                ans[left] = -x;
                left += 1;
                neg -= x;
            } else {
                ans[right] = x;
                right -= 1;
            }
        }
        return ans;
    }
};