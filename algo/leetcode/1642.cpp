#include <bits/stdc++.h>
using namespace std;

// 1642. Furthest Building You Can Reach [M]
// LeetCode furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // 使用最小堆来跟踪使用梯子的高度差
        // 这样可以方便地找到最小的梯子使用，必要时用砖块替换
        priority_queue<int, vector<int>, greater<int>> ladder_diffs;
        
        // 记录使用的砖块总数
        long long bricks_used = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) continue; // 如果下一个建筑物更矮或等高，不需要任何资源
            
            // 将当前高度差加入梯子使用的堆中
            ladder_diffs.push(diff);
            
            // 如果使用的梯子数量超过了可用梯子数
            if (ladder_diffs.size() > ladders) {
                // 取出最小的梯子使用，改为使用砖块
                bricks_used += ladder_diffs.top();
                ladder_diffs.pop();
            }
            
            // 如果使用的砖块超过了可用砖块，返回当前位置
            if (bricks_used > bricks) {
                return i;
            }
        }
        
        // 如果能够到达最后一个建筑物，返回n-1
        return n - 1;
    }
};