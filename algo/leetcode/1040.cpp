#include <bits/stdc++.h>
using namespace std;

// 1040. Moving Stones Until Consecutive II [M]
// LeetCode moving-stones-until-consecutive-ii

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        // 首先对石子位置进行排序，方便后续处理
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int low = n; // 初始化最小移动次数为最大值n
        
        // 使用滑动窗口法计算最小移动次数
        int left = 0, right = 0;
        while (right < n) {
            // 调整窗口左边界，使得窗口内的石子位置范围不超过n
            while (stones[right] - stones[left] + 1 > n) {
                left += 1;
            }
            
            int len = right - left + 1; // 当前窗口内的石子数量
            
            // 特殊情况处理：当窗口内有n-1个石子且它们连续时
            if (len == n - 1 && stones[right] - stones[left] + 1 == n - 1) {
                low = min(low, 2); // 这种情况需要至少2次移动
            } else {
                // 一般情况下，需要移动的次数是总石子数减去窗口内已有的石子数
                low = min(low, n - len);
            }
            
            right += 1; // 扩展窗口右边界
        }
        
        // 计算最大移动次数
        // 有两种可能的最大移动方案：
        // 1. 将最左边的石子移到最右边石子的旁边
        // 2. 将最右边的石子移到最左边石子的旁边
        // 取这两种方案中的较大值
        int high = max(
            stones[n - 1] - stones[1] - (n - 2),  // 方案1
            stones[n - 2] - stones[0] - (n - 2)   // 方案2
        );
        
        return {low, high};
    }
};