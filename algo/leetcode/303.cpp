#include <bits/stdc++.h>
using namespace std;

// 303. Range Sum Query - Immutable [E]
// LeetCode range-sum-query-immutable

class NumArray {
private:
    vector<int> pre_sum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre_sum.assign(n + 1, 0);
        for(int i = 0; i < n; i ++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */