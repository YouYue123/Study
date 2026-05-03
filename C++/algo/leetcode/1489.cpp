#include <bits/stdc++.h>
using namespace std;

// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree [H]
// LeetCode find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree

struct UF {
    vector<int> parent;
    vector<int> size;
    int connected_size = 0;
    int n;
    UF (int n): n(n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }

    void unite (int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
        connected_size += 1;
    }

    int find_root (int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }
    bool is_connect (int x, int y) {
        return find_root(x) == find_root(y);
    }
};
struct Edge {
    int a;
    int b;
    int w;
    int idx;
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> items;
        for(int i = 0; i < edges.size(); i ++) {
             auto& e = edges[i];
            int a = e[0], b = e[1], w = e[2];
            items.emplace_back(a, b, w, i);
        }
        sort(items.begin(), items.end(), [&](auto& a, auto& b) {
            return a.w < b.w;
        });
        vector ans(2, vector<int>());
        auto get_mst_weight = [&] (Edge* exclude, Edge* include) -> int {
            UF uf(n);
            int weight = 0;
            if(include) {
                uf.unite(include->a, include->b);
                weight += include->w;
            }
            for(auto& item : items) {
                if(exclude && exclude->idx == item.idx) continue;
                if(!uf.is_connect(item.a, item.b)) {
                    uf.unite(item.a, item.b);
                    weight += item.w;
                }
            }
            // cout << "connected_size: " << uf.connected_size << endl;
            if(uf.connected_size != n - 1) return -1; 
            return weight;
        };
       
        int target_weight = get_mst_weight(nullptr, nullptr);
        // cout << "target_weight: " << target_weight << endl; 
        for(auto& item : items) {
            // cout << "for idx " << item.idx << " " << item.a << " " << item.b << " " << item.w << endl;
            // cout << "if exclude " << get_mst_weight(&item, nullptr) << endl;
            // cout << "if include " << get_mst_weight(nullptr, &item) << endl; 
            if(get_mst_weight(&item, nullptr) != target_weight) {
                // critical, can not exclude
                ans[0].push_back(item.idx);
                continue;
            }
            if(get_mst_weight(nullptr, &item) == target_weight) {
                // pseudo-critical, can exclude but can also use
                ans[1].push_back(item.idx);
            }
        }
        return ans;
    }
};