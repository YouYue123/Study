#include <bits/stdc++.h>
using namespace std;

// 121. Best Time to Buy and Sell Stock [E]
// LeetCode best-time-to-buy-and-sell-stock

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = INF;
        int ans = 0;
        for(int price : prices) {
            ans = max(ans, price - cur_min);
            cur_min = min(cur_min, price);
        }
        return ans;
    }
};