#include <bits/stdc++.h>
using namespace std;

// 3912. Valid Elements in an Array [E]
// LeetCode valid-elements-in-an-array

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> left_max(n, -INF);
        for(int i = 1; i < n; i ++) {
            left_max[i] = max(left_max[i - 1], nums[i - 1]);
        }
        vector<int> right_max(n, -INF);
        for(int i = n - 2; i >= 0; i --) {
            right_max[i] = max(right_max[i + 1], nums[i + 1]);
        }
        for(int i = 0; i < n; i ++) {
            if(nums[i] > left_max[i] || nums[i] > right_max[i]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};