#include <bits/stdc++.h>
using namespace std;

// 2210. Count Hills and Valleys in an Array [E]
// LeetCode count-hills-and-valleys-in-an-array

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int left = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                    (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    ans += 1;
                }
                left = i;
            }
        }

        return ans;
    }
};