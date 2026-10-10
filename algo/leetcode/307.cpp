#include <bits/stdc++.h>
using namespace std;

// 307. Range Sum Query - Mutable [M]
// LeetCode range-sum-query-mutable

struct BIT {
    vector<int> nums;
    BIT (int n) {
        nums.assign(n + 1, 0);
    }
    int lowbit(int x) {
        return x & (-x);
    }

    void add(int idx, int delta) {
        int n = nums.size();
        while(idx < n) {
            nums[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int get(int idx) {
        int ans = 0;
        while(idx > 0) {
            ans += nums[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
};
class NumArray {
private:
 BIT* bit;
 vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        bit = new BIT(n);
        this->nums = nums;
        for(int i = 0; i < nums.size(); i ++) {
            bit->add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        bit->add(index + 1, delta);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return bit->get(right + 1) - bit->get(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */