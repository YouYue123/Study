#include <bits/stdc++.h>
using namespace std;

// 1848. Minimum Distance to the Target Element [E]
// LeetCode minimum-distance-to-the-target-element

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = INF;
        for(int i = 0; i < n; i ++) {
            if(nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};