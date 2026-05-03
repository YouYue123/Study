#include <bits/stdc++.h>
using namespace std;

// 1724. Checking Existence of Edge Length Limited Paths II [H]
// LeetCode checking-existence-of-edge-length-limited-paths-ii

class DistanceLimitedPathsExist {
    struct Edge { int u, v, w; };
    vector<int> val;        // 存储重构树中每个点的权重
    vector<int> parent;     // 并查集使用
    vector<vector<int>> up; // 倍增法求LCA
    vector<int> depth;
    int max_val_node;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // 预处理倍增表 (LCA)
    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < 20; i++) {
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for (int v : adj[u]) {
            dfs(v, u, d + 1, adj);
        }
    }

public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        int m = edgeList.size();
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        // 重构树最多有 2n-1 个节点 (n个叶子, n-1个合成点)
        val.resize(2 * n, 0);
        parent.resize(2 * n);
        for (int i = 0; i < 2 * n; i++) parent[i] = i;
        
        vector<vector<int>> adj(2 * n);
        int curr_node = n; // 新节点的起始编号

        for (auto& e : edgeList) {
            int root_u = find(e[0]), root_v = find(e[1]);
            if (root_u != root_v) {
                val[curr_node] = e[2]; // 虚拟节点记录边权
                parent[root_u] = parent[root_v] = curr_node;
                adj[curr_node].push_back(root_u);
                adj[curr_node].push_back(root_v);
                curr_node++;
            }
        }

        max_val_node = curr_node;
        up.assign(max_val_node, vector<int>(20, 0));
        depth.resize(max_val_node, 0);
        
        // 处理森林情况（如果图不连通，有多个根）
        for (int i = max_val_node - 1; i >= 0; i--) {
            if (parent[i] == i) { // 找到每个连通分量的根
                dfs(i, i, 0, adj);
            }
        }
    }

    bool query(int p, int q, int limit) {
        // 如果不在同一个连通分量，直接返回 false
        if (find(p) != find(q)) return false;

        // 求 LCA
        int u = p, v = q;
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = 19; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
        }
        if (u != v) {
            for (int i = 19; i >= 0; i--) {
                if (up[u][i] != up[v][i]) {
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            u = up[u][0];
        }
        
        // LCA 的权值就是路径上的“瓶颈”
        return val[u] < limit;
    }
};