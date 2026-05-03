#include <bits/stdc++.h>
using namespace std;

// 1685. Sum of Absolute Differences in a Sorted Array [M]
// LeetCode sum-of-absolute-differences-in-a-sorted-array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> presum(n + 1, 0);
        for(int i = 1; i <= n; i ++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        for(int i = 0; i < n; i ++) {
            int pre = presum[i] - presum[0];
            int post = presum[n] - presum[i];
            // cout << pre << " " << post << endl;
            int curAns = i * nums[i] - pre + post - (n - i) *  nums[i];
            ans.push_back(curAns);
        }
        return ans;
    }
};