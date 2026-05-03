#include <bits/stdc++.h>
using namespace std;

// 3585. Find Weighted Median Node in Tree [H]
// LeetCode find-weighted-median-node-in-tree

struct LCA {
public:
    int n;
    int log_n;
    vector<vector<int>> parent; 
    vector<int> depth;
    vector<long long> dist_from_root; 

    void dfs(int u, int p, int d, long long current_dist, const unordered_map<int, vector<pair<int, int>>>& graph) {
        depth[u] = d;
        parent[0][u] = p;
        dist_from_root[u] = current_dist;
        if (graph.count(u)) {
            for (const auto& edge : graph.at(u)) {
                int v = edge.first;
                long long w = edge.second;
                if (v != p) {
                    dfs(v, u, d + 1, current_dist + w, graph);
                }
            }
        }
    }
    LCA(int num_nodes, const unordered_map<int, vector<pair<int, int>>>& graph) {
        n = num_nodes;
        log_n = (n == 0) ? 0 : floor(log2(n)) + 1;
        parent.assign(log_n, vector<int>(n, -1));
        depth.assign(n, 0);
        dist_from_root.assign(n, 0LL);
        dfs(0, -1, 0, 0LL, graph);
        parent[0][0] = 0;
        for (int k = 1; k < log_n; ++k) {
            for (int i = 0; i < n; ++i) {
                parent[k][i] = parent[k - 1][parent[k - 1][i]];
            }
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = log_n - 1; k >= 0; --k) {
            if (depth[u] - (1 << k) >= depth[v]) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = log_n - 1; k >= 0; --k) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    long long get_distance(int u, int v) {
        int lca_node = get_lca(u, v);
        return (dist_from_root[u] - dist_from_root[lca_node]) + (dist_from_root[v] - dist_from_root[lca_node]);
    }

    vector<int> findMedian(int n_nodes, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto& e : edges) {
            graph[e[0]].push_back({ e[1], e[2] });
            graph[e[1]].push_back({ e[0], e[2] });
        }

        vector<int> ans;
        for(auto& q : queries) {
            int u = q[0], v = q[1];
            if(u == v) {
                ans.push_back(u);
                continue;
            }

            int lcaNode = this->get_lca(u, v);
            long long totalDist = this->get_distance(u, v);
            double halfDist = (double)totalDist / 2.0;

            long long distUToLca = this->get_distance(u, lcaNode);

            if(distUToLca >= halfDist) {
                int cur = u;
                for(int k = this->log_n - 1; k >= 0; --k) {
                    int ancestor = this->parent[k][cur];
                    if (ancestor != -1 && this->depth[ancestor] >= this->depth[lcaNode]) {
                        if ((this->dist_from_root[u] - this->dist_from_root[ancestor]) < halfDist) {
                            cur = ancestor;
                        }
                    }
                }
                ans.push_back(this->parent[0][cur]);
            } else {
                double remaining = halfDist - distUToLca;
                double targetDistFromRoot = this->dist_from_root[lcaNode] + remaining;                
                int cur = v;
                for(int k = this->log_n - 1; k >= 0; --k) {
                    int ancestor = this->parent[k][cur];
                    if(ancestor != -1 && this->depth[ancestor] >= this->depth[lcaNode]) {
                        if (this->dist_from_root[ancestor] >= targetDistFromRoot) {
                            cur = ancestor;
                        }
                    }
                }
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto& e : edges) {
            graph[e[0]].push_back({ e[1], e[2] });
            graph[e[1]].push_back({ e[0], e[2] });
        }
        LCA lca_resolver(n, graph);
        return lca_resolver.findMedian(n, edges, queries);
    }
};