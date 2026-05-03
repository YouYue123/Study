#include <bits/stdc++.h>
using namespace std;

// 2073. Time Needed to Buy Tickets [E]
// LeetCode time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        // tickets[k] - 1 round:
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            if(i <= k) {
                ans += min(tickets[i], tickets[k]);
            } else if(i > k) {
                ans += min(tickets[i], tickets[k] - 1);
            }
        }
        return ans;
    }
};