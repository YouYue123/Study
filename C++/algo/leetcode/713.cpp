#include <bits/stdc++.h>
using namespace std;

// 713. Subarray Product Less Than K [M]
// LeetCode subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int left = 0, right = 0;  // 滑动窗口的左右指针
        long long mul = 1;        // 当前窗口内元素的乘积
        int ans = 0;              // 结果计数器
        
        while(right < nums.size()) {
            // 将右指针指向的元素乘入当前乘积
            mul *= nums[right];
            
            // 当乘积超过或等于k时，移动左指针缩小窗口
            while(mul >= k) {
                mul /= nums[left];
                left += 1;
            }
            
            ans += right - left + 1;
            // 移动右指针扩大窗口
            right += 1;
        }
        
        return ans;
    }
};