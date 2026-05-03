#include <bits/stdc++.h>
using namespace std;

// 3152. Special Array II [M]
// LeetCode special-array-ii

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
         vector<int> preSum(nums.size(), 0);
         for(int i = 1; i < nums.size(); i ++) {
            preSum[i] = preSum[i - 1];
            if(nums[i] % 2 == nums[i - 1] % 2) {
                preSum[i] += 1;
            }
         }
         vector<bool> ans;
         for(auto& q : queries) {
            int from = q[0], to = q[1];
            ans.push_back(
                preSum[to] - preSum[from] == 0
            );
         };
         return ans;
    }
};