#include <bits/stdc++.h>
using namespace std;

// 624. Maximum Distance in Arrays [M]
// LeetCode maximum-distance-in-arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int curMin = arrays[0].front();
        int curMax = arrays[0].back();
        int ans = INT_MIN;
        for(int i = 1; i < arrays.size(); i ++) {
            auto arr = arrays[i];
            ans = max({
                ans,
                abs(arr.back() - curMin),
                abs(curMax - arr.front())
            });
            // cout << curMin << " " << curMax << endl;
            curMin = min(curMin, arr.front());
            curMax = max(curMax, arr.back());
        }
        return ans;
    }
};