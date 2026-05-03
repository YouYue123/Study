#include <bits/stdc++.h>
using namespace std;

// 1584. Min Cost to Connect All Points [M]
// LeetCode min-cost-to-connect-all-points

using pii = pair<int, int>; // {距离, 目标点索引}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        int count = 0; // 记录已加入 MST 的点数
        vector<bool> visited(n, false);
        
        // 小根堆，存储 {到该点的距离, 点的索引}
        // 默认 pair 比较是先比第一个元素，所以距离放在前面
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // 从 0 号点开始
        pq.push({0, 0});

        while (!pq.empty() && count < n) {
            auto [dist, u] = pq.top();
            pq.pop();

            // 如果这个点已经进过树了，直接跳过（重要！）
            if (visited[u]) continue;

            // 1. 正式加入 MST
            visited[u] = true;
            ans += dist;
            count++;

            // 2. 扫描 u 的所有邻居（在全连接图中，邻居就是所有其他点）
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int d = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    // 将可能的更短边压入优先队列
                    pq.push({d, v});
                }
            }
        }
        return ans;
    }
};