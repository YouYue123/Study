#include <bits/stdc++.h>
using namespace std;

// 3511. Make a Positive Array [M]
// LeetCode make-a-positive-array

class Solution {
public:
    int makeArrayPositive(vector<int>& nums) {
        long long ans = 0, curMax = 0, sum = 0, n = nums.size();
        vector<long long> preSum;
        for(int i = 0; i < n; i ++) {
            sum += nums[i];
            preSum.push_back(sum);
            if(preSum.size() > 3) {
                curMax = max(curMax, preSum[preSum.size() - 4]);
            }
            if(preSum.size() > 2 && sum - curMax <= 0) {
                ans += 1;
                sum = 0;
                curMax = 0;
                preSum.clear();
            }
        }
        return ans;
    }
};