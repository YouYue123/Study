#include <bits/stdc++.h>
using namespace std;

// 2090. K Radius Subarray Averages [M]
// LeetCode k-radius-subarray-averages

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        int left = 0, right = 0;
        long sum = 0;
        int len = k * 2 + 1;
        while(right < nums.size()) {
            sum += nums[right];
            if(right - left  + 1 > len) {
                sum -= nums[left];
                left += 1;
            }
            if(right - left + 1 == len) {
                int mid = left + (right - left) / 2;
                ans[mid] = sum / len;
            }
            right += 1;
        }
        return ans;
    }
};