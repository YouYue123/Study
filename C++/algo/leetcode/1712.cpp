#include <bits/stdc++.h>
using namespace std;

// 1712. Ways to Split Array Into Three Subarrays [M]
// LeetCode ways-to-split-array-into-three-subarrays

class Solution {
    // 定义常量 MOD 为 10^9 + 7，用于模运算以防止溢出
    static constexpr int MOD = 1e9 + 7;
public:
    // 函数用于计算将数组分成三个非空部分的合法方式数量
    int waysToSplit(vector<int>& nums) {
        // 获取输入数组的大小
        int n = nums.size();
        
        // 创建前缀和数组，大小为 n+1，用于存储累计和
        // preSum[i] 表示从 nums[0] 到 nums[i-1] 的和
        vector<long long> preSum(n + 1);
        
        // 计算前缀和
        // preSum[0] = 0, preSum[1] = nums[0], preSum[2] = nums[0] + nums[1], 依此类推
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        
        // 初始化左右指针，用于滑动窗口
        // 都从 1 开始，因为第一部分必须非空
        int left = 1;
        int right = 1;
        
        // 存储最终答案（合法分割的数量）
        long long ans = 0;
        
        // 遍历第一个部分的可能的结束点
        // i 表示第一部分结束的索引（0 到 i）
        // 需要至少留 2 个元素给第二和第三部分
        for (int i = 1; i < n - 1; ++i) {
            // 计算第三部分的和（从 i+1 到末尾）
            int rightSum = preSum[n] - preSum[i + 1];
            
            // 移动右指针直到第二部分和 >= 第一部分和
            // 条件：从 right 到 i+1 的和 >= 从 0 到 right 的和
            while (right <= i && preSum[i + 1] - preSum[right] >= preSum[right]) {
                ++right;
            }
            
            // 移动左指针直到第二部分和 <= 第三部分和
            // 条件：从 left 到 i+1 的和 <= 从 i+1 到末尾的和
            while (left <= i && preSum[i + 1] - preSum[left] > rightSum) {
                ++left;
            }
            
            // 添加当前 i 的合法分割数量
            // max(right - left, 0) 确保不添加负数
            // 取模防止溢出
            ans = (ans + max(right - left, 0)) % MOD;
        }
        
        // 返回最终答案，转换为整数
        return ans;
    }
};