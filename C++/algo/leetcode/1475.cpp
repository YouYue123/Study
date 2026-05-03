#include <bits/stdc++.h>
using namespace std;

// 1475. Final Prices With a Special Discount in a Shop [E]
// LeetCode final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(prices.begin(), prices.end());
        for(int i = 0 ; i < n; i ++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] = ans[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};