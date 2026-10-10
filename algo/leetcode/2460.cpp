#include <bits/stdc++.h>
using namespace std;

// 2460. Apply Operations to an Array [E]
// LeetCode apply-operations-to-an-array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size();) {
            if(nums[i] == 0) {
                i+=1;
            } else if (i+1 < nums.size() && nums[i] == nums[i + 1]) {
                ans.push_back(nums[i] * 2);
                i+=2;
            } else {
                ans.push_back(nums[i]);
                i += 1;
            }
        }
        for(int i = ans.size(); i < nums.size(); i ++) {
            ans.push_back(0);
        }
        return ans;
    }
};