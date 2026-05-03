// 2812. Find the Safest Path in a Grid [M]
// LeetCode find-the-safest-path-in-a-grid

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 建议给 struct 增加 const 限定符，防止编译器报错
struct Node {
    int x, y, safe;
    bool operator<(const Node& other) const {
        return safe < other.safe; // 大顶堆，安全系数高的优先
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // 如果起点或终点直接就是敌人，安全系数为 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // 1. 多源 BFS 预处理每个点到最近敌人的距离
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& d : dirs) {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && safeness[nx][ny] == -1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // 2. 使用 Dijkstra 寻找最大安全路径
        priority_queue<Node> pq;
        // res[i][j] 记录到达 (i,j) 路径上能维持的最大“最小安全距离”
        vector<vector<int>> res(n, vector<int>(n, -1));

        pq.push({0, 0, safeness[0][0]});
        res[0][0] = safeness[0][0];

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            // 提前剪枝：如果当前路径的安全系数已经小于记录的最优解，跳过
            if (cur.safe < res[cur.x][cur.y]) continue;
            if (cur.x == n - 1 && cur.y == n - 1) return cur.safe;

            for (auto& d : dirs) {
                int nx = cur.x + d.first, ny = cur.y + d.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    // 路径上的安全系数取决于木桶效应：当前和下一步中较小的那个
                    int nextSafe = min(cur.safe, safeness[nx][ny]);
                    if (nextSafe > res[nx][ny]) {
                        res[nx][ny] = nextSafe;
                        pq.push({nx, ny, nextSafe});
                    }
                }
            }
        }

        return 0;
    }
};