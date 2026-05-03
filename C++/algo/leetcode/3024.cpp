#include <bits/stdc++.h>
using namespace std;

// 3024. Type of Triangle [E]
// LeetCode type-of-triangle

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums.size() != 3) return "none";
        if(nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) return "none";
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";
        else return "scalene";
        return "none";
    }
};