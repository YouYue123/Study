#include <bits/stdc++.h>
using namespace std;

// 2260. Minimum Consecutive Cards to Pick Up [M]
// LeetCode minimum-consecutive-cards-to-pick-up

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> dict;
        int ans = INT_MAX;
        for(int i = 0; i < cards.size(); i ++) {
            int card = cards[i];
            if(dict.contains(card)) {
                ans = min(ans, i - dict[card] + 1);
            }
            dict[card] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};