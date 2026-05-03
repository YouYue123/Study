// 475. Heaters [M]
// LeetCode heaters

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 首先对加热器进行排序，以便使用二分查找
        sort(heaters.begin(), heaters.end());
        int ans = 0; // 初始化最小加热半径为0
        
        // 遍历每一个房子
        for(int h: houses) {
            // 使用 lower_bound 找到第一个不小于 h 的加热器位置
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            
            // 计算右边加热器的距离
            int distRight = (it == heaters.end()) ? INT_MAX : *it - h;
            
            // 计算左边加热器的距离
            int distLeft = (it == heaters.begin()) ? INT_MAX : h - *(--it);
            
            // 当前房子的最小覆盖半径是左右距离中的较小者
            // 全局的最小加热半径是所有房子最小覆盖半径的最大值
            ans = max(ans, min(distRight, distLeft));
        }
        return ans;
    }
};