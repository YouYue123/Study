#include <bits/stdc++.h>
using namespace std;

// 1744. Can You Eat Your Favorite Candy on Your Favorite Day? [M]
// LeetCode can-you-eat-your-favorite-candy-on-your-favorite-day

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = candiesCount.size();
        vector<long long> preSum(n + 1, 0);
        for(int i = 1; i <= n; i ++) {
            preSum[i] = preSum[i - 1] + candiesCount[i - 1];
        }
        for(vector<int>& q : queries) {
            long long fType = q[0], fDay = q[1], cap = q[2];
            // Can eat if fDay is within the possible range:
            // - Not too late (haven't eaten all candies of this type or before at 1 candy/day).
            // - Not too early (can reach this candy type by fDay at max capacity `cap`).
            if(fDay >= preSum[fType + 1] || fDay * cap + cap <= preSum[fType] ) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }
        return ans;
    }
};