#include <bits/stdc++.h>
using namespace std;

// 976. Largest Perimeter Triangle [E]
// LeetCode largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int a = 0, b = 1, c = nums.size() - 1;
        int ans = 0;
        while(c > 1) {
            int left = c - 2, right =  c - 1;
            if(nums[left] + nums[right] > nums[c]) {
                ans = max(ans, nums[left] + nums[right] + nums[c]);
            }
            c -= 1;
        }
        return ans;
    }
};