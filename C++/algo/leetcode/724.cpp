#include <bits/stdc++.h>
using namespace std;

// 724. Find Pivot Index [E]
// LeetCode find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        for(int i = 0; i < n; i ++) {
            int right_sum = total_sum - left_sum - nums[i];
            // cout << cur_sum << endl;
            // cout << total_sum - cur_sum << endl;
            if(right_sum == left_sum) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};