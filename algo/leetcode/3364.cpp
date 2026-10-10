#include <bits/stdc++.h>
using namespace std;

// 3364. Minimum Positive Sum Subarray  [E]
// LeetCode minimum-positive-sum-subarray

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> presum(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i ++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i ++) {
            for(int j = i; j < nums.size(); j ++) {
                int curLen = j - i + 1;
                // cout << i << " " << j << endl;
                if(curLen > r) break;
                if(curLen >= l) {
                    // [i, j]
                    int curSum = presum[j + 1] - presum[i];
                    // cout << curSum << endl;
                    if(curSum > 0) {
                        ans = min(ans, curSum);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};