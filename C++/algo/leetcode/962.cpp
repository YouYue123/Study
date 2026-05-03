#include <bits/stdc++.h>
using namespace std;

// 962. Maximum Width Ramp [M]
// LeetCode maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> monoSt;
        monoSt.push(0);
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            if(nums[monoSt.top()] > num) {
                monoSt.push(i);
            }
        }
        int ans = 0;
        for(int i = n - 1; i >= 0; i --) {
            while(!monoSt.empty() && nums[monoSt.top()] <= nums[i]) {
                ans = max(ans, i - monoSt.top());
                monoSt.pop();
            }
        }
        return ans;
    }
};