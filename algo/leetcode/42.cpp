#include <bits/stdc++.h>
using namespace std;

// 42. Trapping Rain Water [H]
// LeetCode trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = height[0], right_max = height[n - 1];
        int ans = 0;
        while(left <= right) {
            if(left_max < right_max) {
                ans += max(
                    min(left_max, right_max) - height[left],
                    0
                );
                left_max = max(height[left], left_max);
                left += 1;
            } else {
                ans += max(
                    min(left_max, right_max) - height[right],
                    0
                );
                right_max = max(height[right], right_max);
                right -= 1;
            }
            // cout << left << " " << right << endl;
            // cout << ans << endl;
        }
        return ans;
    }
};