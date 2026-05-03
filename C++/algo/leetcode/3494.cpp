#include <bits/stdc++.h>
using namespace std;

// 3494. Find the Minimum Amount of Time to Brew Potions [M]
// LeetCode find-the-minimum-amount-of-time-to-brew-potions

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> lastFinish(n, 0);
        for(int m : mana) {
            long long presum = 0;
            for(int i = 0; i < n; i ++) {
                presum = max(presum, lastFinish[i]) + skill[i] * m;
            }
            lastFinish[n - 1] = presum;
            for(int i = n - 2; i >= 0; i --) {
                lastFinish[i] = lastFinish[i + 1] - (skill[i + 1] * m);
            }
        }
        return lastFinish[n - 1];
    }
};