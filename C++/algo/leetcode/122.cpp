#include <bits/stdc++.h>
using namespace std;

// 122. Best Time to Buy and Sell Stock II [M]
// LeetCode best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for(int i = 1; i < n; i ++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};