#include <bits/stdc++.h>
using namespace std;
int constexpr INF = 0x3f3f3f3f;
/**
 * 【知识库】最短访问路径 (Shortest Path Visiting All Nodes) - 状态压缩 DP 
 * * * 1. 核心转化 (Graph Reduction):
 * - 原问题：在图中寻找一条路径经过所有点，允许重复经过点和边。
 * - 转化后：先计算【全源最短路 (APSP)】，将原图看作一个“完全图”。
 * - 在完全图中，两点间的边权重即为原图中的最短距离。这使得问题转化为经典的 TSP (旅行商问题)。
 * 
 * * * 2. 预计算最短路 (Preprocessing):
 * - 无权图：对每个点跑一遍 BFS，复杂度 O(N*(N+E))。
 * - 有权图：使用 Floyd-Warshall (O(N³)) 或 N 次 Dijkstra (O(N*E log N))。
 * 
 * * * 3. 状态定义 (State Compression):
 * - dp[mask][curr]: 
 * - mask: 二进制位表示哪些节点已被访问（1 为已访问）。
 * - curr: 当前所处的最后一个节点索引。
 * 
 * * * 4. 转移方程 (Transition):
 * - dp[mask | (1 << next)][next] = min(dp[mask | (1 << next)][next], dp[mask][curr] + dist[curr][next])
 * - 意义：从当前点 curr “跳跃”到下一个未访问的点 next，代价是两点间的最短路径。
 * 
 * * * 5. 复杂度分析:
 * - 时间复杂度: O(N*(N+E) + N² * 2ⁿ)。
 * - 空间复杂度: O(2ⁿ * N)，主要消耗在记忆化数组（memo）。
 */
struct Node {
    int idx;
    int dist;
    bool operator<(const Node& other) const {
        return dist < other.dist;
    }
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int full = (1 << n) - 1;
        vector dist(n, vector(n, INF));
        // for(int i = 0; i < n; i ++) {
        //     dist[i][i] = 0;
        //     for(int j = i + 1; j < n; j ++) {
        //         priority_queue<Node, vector<Node>, greater<>> pq;
        //         vector minD(n, INF);
        //         pq.emplace(i, 0);
        //         while(!pq.empty()) {
        //             auto cur = pq.top();
        //             pq.pop();
        //             if(cur.idx == j) break;
        //             for(int nxt : graph[cur.idx]) {
        //                 int nxtDist = cur.dist + 1;
        //                 if(minD[nxt] <= nxtDist) continue;
        //                 minD[nxt] = nxtDist;
        //                 pq.emplace(nxt, nxtDist);
        //             }
        //         }
        //         dist[i][j] = minD[j];
        //         dist[j][i] = minD[j];
        //     }
        // }
        for(int i = 0; i < n; i ++) {
            dist[i][i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : graph[u]) {
                    if(dist[i][v] == INF) {
                        dist[i][v] = dist[i][u] + 1;
                        q.push(v);
                    }
                }
            }
         }
        vector memo(1 << n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int state, int prev) {
            if(full == state) return 0;
            if(memo[state][prev] != -1) return memo[state][prev];
            int ans = INF;
            for(int i = 0; i < n; i ++) {
                if(state & (1 << i)) continue;
                int d = dist[prev][i];
                ans = min(
                    ans,
                    dfs(state | (1 << i), i) + d
                );
            }
            return memo[state][prev] = ans;
        };
        int ans = INF;
        for(int i = 0; i < n; i ++) {
            ans = min(ans, dfs(1 << i, i));
        }
        return ans;
    }
};