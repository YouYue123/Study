// 1610. Maximum Number of Visible Points [H]
// LeetCode maximum-number-of-visible-points

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

#define PI 3.14159265

struct Node {
    int x;
    int y;
    double angle;
    
    Node(int x, int y, const vector<int>& location) : x(x), y(y) {
        // 计算当前点相对于观察点的角度（弧度）
        double radian = atan2(y - location[1], x - location[0]);
        // 转换为角度并规范化到[0, 360)范围
        angle = radian * 180 / PI;
        angle = fmod(angle + 360, 360);
    }
    
    // 重载运算符用于排序
    bool operator<(const Node& other) const {
        return angle < other.angle;
    }
};

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<Node> nodes;
        int samePointCount = 0; // 记录与观察点重合的点数
        
        // 1. 预处理所有点，计算角度并过滤重合点
        for (const auto& p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                samePointCount++;
                continue;
            }
            nodes.emplace_back(p[0], p[1], location);
        }
        
        // 2. 按角度排序
        sort(nodes.begin(), nodes.end());
        
        // 3. 处理循环角度问题：将角度小于angle的点复制一份并加上360
        int n = nodes.size();
        for (int i = 0; i < n; i++) {
            if (nodes[i].angle < angle) {
                Node node = nodes[i];
                node.angle += 360;
                nodes.push_back(node);
            }
        }
        
        // 4. 滑动窗口寻找最大可见点数
        int left = 0;
        int maxVisible = 0;
        
        for (int right = 0; right < nodes.size(); right++) {
            // 调整左指针使窗口内角度差不超过angle
            while (nodes[right].angle - nodes[left].angle > angle) {
                left++;
            }
            // 更新最大可见点数
            maxVisible = max(maxVisible, right - left + 1);
        }
        
        // 最终结果为窗口最大值加上重合点数
        return maxVisible + samePointCount;
    }
};