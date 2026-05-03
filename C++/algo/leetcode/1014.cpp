#include <bits/stdc++.h>
using namespace std;

// 1014. Best Sightseeing Pair [M]
// LeetCode best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int curMax = -1;
        for(int i = 0; i < values.size(); i ++) {
            int val = values[i];
            ans = max(ans, val + curMax);
            curMax -= 1;
            curMax = max(curMax, val - 1);
        }
        return ans;
    }
};