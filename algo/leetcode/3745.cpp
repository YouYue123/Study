#include <bits/stdc++.h>
using namespace std;

// 3745. Maximize Expression of Three Elements [E]
// LeetCode maximize-expression-of-three-elements

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                for(int k = j + 1; k < n; k ++) {
                    ans = max({
                       ans, nums[i] + nums[j] - nums[k],
                        nums[i] + nums[k] - nums[j],
                        nums[k] + nums[j] - nums[i]
                    });
                }
            }
        }
        return ans;
    }
};