#include <bits/stdc++.h>
using namespace std;

// 2025. Maximum Number of Ways to Partition an Array [H]
// LeetCode maximum-number-of-ways-to-partition-an-array


class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<long long> sum(n);
        sum[0] = nums[0];
        unordered_map<long long, int> left, right;
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + nums[i];
            right[sum[i - 1]]++;
        }
        long long total = sum[n - 1];
        if (total % 2 == 0) ans = right[total / 2];
        //left表示当修改nums[i]为k时，分隔位pivot小于i存放的前缀和，同理right表示大于或者等于。
        for (int i = 0; i < n; ++i) {
            int dif = k - nums[i];
            if ((total + dif) % 2 == 0) {
                //cr + dif == (tot + dif) / 2,因为cr的前缀和都包含了修改前的nums[i]
                ans = max(ans, left[(total + dif) / 2] + right[(total - dif) / 2]);
            }
            left[sum[i]]++;
            right[sum[i]]--;
        }
        return ans;
    }
};