#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Structure for finding the Lowest Common Ancestor (LCA) and distances in a tree.
 * * This implementation uses binary lifting for efficient LCA queries. It also pre-calculates
 * depths and distances from the root to answer distance queries between any two nodes.
 */
struct LCA {
public:
    int n; // Number of nodes in the tree.
    int log_n; // Maximum power of 2 less than or equal to n, used for binary lifting.
    vector<vector<int>> parent; // parent[k][i] stores the 2^k-th ancestor of node i.
    vector<int> depth; // Stores the depth of each node (distance from the root).
    vector<long long> dist_from_root; // Stores the cumulative distance from the root to each node.

    /**
     * @brief Performs a Depth First Search (DFS) to initialize depths, parents, and distances.
     * * @param u The current node.
     * @param p The parent of the current node.
     * @param d The depth of the current node.
     * @param current_dist The distance from the root to the current node.
     * @param graph The adjacency list representation of the tree, where each edge has a weight.
     */
    void dfs(int u, int p, int d, long long current_dist, const unordered_map<int, vector<pair<int, int>>>& graph) {
        depth[u] = d;
        parent[0][u] = p; // The immediate parent (2^0-th ancestor).
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

    /**
     * @brief Constructor for the LCA structure.
     * * @param num_nodes The total number of nodes in the tree.
     * @param graph The adjacency list of the tree.
     */
    LCA(int num_nodes, const unordered_map<int, vector<pair<int, int>>>& graph) {
        n = num_nodes;
        log_n = (n == 0) ? 0 : floor(log2(n)) + 1;
        parent.assign(log_n, vector<int>(n, -1));
        depth.assign(n, 0);
        dist_from_root.assign(n, 0LL);
        
        // Start DFS from the root (node 0) with no parent (-1).
        dfs(0, -1, 0, 0LL, graph);

        // The root's parent is itself.
        parent[0][0] = 0; 
        
        // Pre-compute the parent pointers for binary lifting.
        for (int k = 1; k < log_n; ++k) {
            for (int i = 0; i < n; ++i) {
                parent[k][i] = parent[k - 1][parent[k - 1][i]];
            }
        }
    }

    /**
     * @brief Finds the Lowest Common Ancestor (LCA) of two nodes.
     * * @param u The first node.
     * @param v The second node.
     * @return The LCA of u and v.
     */
    int get_lca(int u, int v) {
        // Ensure u is the deeper node.
        if (depth[u] < depth[v]) swap(u, v);

        // Bring u to the same depth as v.
        for (int k = log_n - 1; k >= 0; --k) {
            if (depth[u] - (1 << k) >= depth[v]) {
                u = parent[k][u];
            }
        }
        
        // If v was an ancestor of u, then v is the LCA.
        if (u == v) return u;
        
        // Move both u and v up until their parents are the same.
        for (int k = log_n - 1; k >= 0; --k) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u]; // The parent of u (and v) is the LCA.
    }

    /**
     * @brief Calculates the distance between two nodes.
     * * @param u The first node.
     * @param v The second node.
     * @return The distance between u and v.
     */
    long long get_distance(int u, int v) {
        int lca_node = get_lca(u, v);
        // The distance is the sum of distances from u and v to the root, minus twice the distance
        // from their LCA to the root.
        return (dist_from_root[u] - dist_from_root[lca_node]) + (dist_from_root[v] - dist_from_root[lca_node]);
    }
};