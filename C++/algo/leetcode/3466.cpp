#include <bits/stdc++.h>
using namespace std;

// 3466. Maximum Coin Collection  [M]
// LeetCode maximum-coin-collection

class Solution {
public:
    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        long long ans = LLONG_MIN / 2, l1 = LLONG_MIN / 2, l2 = LLONG_MIN / 2, l21 = LLONG_MIN / 2;
        for(int i = 0; i < lane1.size(); i ++) {
            l1 = max(0LL, l1) + lane1[i];
            l2 = max(max(0LL, l2) + lane2[i], l1);
            l21 = max(l21 + lane1[i], l2);
            ans = max({ ans, l1, l21 });
        }
        return ans;
    }
};