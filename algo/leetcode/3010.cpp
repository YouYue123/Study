#include <bits/stdc++.h>
using namespace std;

// 3010. Divide an Array Into Subarrays With Minimum Cost I [E]
// LeetCode divide-an-array-into-subarrays-with-minimum-cost-i

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int s = INF, nxtS = INF;
        for(int i = 1; i < n; i ++) {
            if(nums[i] < s) {
                nxtS = s;
                s = nums[i];
            } else if(nums[i] < nxtS) {
                nxtS = nums[i];
            }
        }
        return nums[0] + s + nxtS;
    }
};