#include <bits/stdc++.h>
using namespace std;

// 2576. Find the Maximum Number of Marked Indices [M]
// LeetCode find-the-maximum-number-of-marked-indices

class Solution {
public:
    // 检查是否可以形成k对标记索引
    // 即前k小的数与后k大的数是否满足nums[i] * 2 <= nums[j]
    bool isValid(int k, vector<int>& nums) {
        for (int i = 0; i < k; i++) {
            // 检查前k小的数nums[i]是否满足nums[i] * 2 <= 后k大的数nums[n - k + i]
            if (nums[i] * 2 > nums[nums.size() - k + i]) {
                return false; // 只要有一对不满足，返回false
            }
        }
        return true; // 所有k对都满足，返回true
    }

    int maxNumOfMarkedIndices(vector<int>& nums) {
        // 首先对数组进行升序排序，方便后续配对
        sort(nums.begin(), nums.end());
        
        // 初始化二分搜索的左右边界
        // left: 最小可能的k值（从1开始，因为k=0时标记数为0，无需考虑）
        // right: 最大可能的k值 + 1（即nums.size() / 2 + 1）
        int left = 1, right = nums.size() / 2 + 1;
        
        // 二分搜索寻找最大的k
        while (left < right) {
            int mid = left + (right - left) / 2; // 防止溢出，计算中间值
            cout << mid << endl; // 调试输出，可以删除
            
            if (isValid(mid, nums)) {
                // 如果mid可行，尝试更大的k
                left = mid + 1;
            } else {
                // 如果mid不可行，尝试更小的k
                right = mid;
            }
        }
        
        // 循环结束时，left是第一个不可行的k，所以最大的可行k是left - 1
        // 标记索引数是k * 2
        return (left - 1) * 2;
    }
};