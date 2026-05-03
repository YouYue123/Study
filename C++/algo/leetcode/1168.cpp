// 1168. Optimize Water Distribution in a Village [H]
// LeetCode optimize-water-distribution-in-a-village

struct Edge {
    int a;
    int b;
    int w;
};
struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }
    void unite(int x, int y) {
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
    }
    int find_root(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }
    bool is_connect(int x, int y) {
        return find_root(x) == find_root(y);
    }
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<Edge> all_edges;
        for(int i = 0; i < n; i ++) {
            all_edges.emplace_back(0, i + 1, wells[i]);
        }
        for(auto& p : pipes) {
            all_edges.emplace_back(p[0], p[1], p[2]);
        }
        sort(all_edges.begin(), all_edges.end(), [&] (auto& a, auto& b) {
            return a.w < b.w;
        });
        UF uf(n + 1);
        int ans = 0;
        for(auto& e : all_edges) {
            if(!uf.is_connect(e.a, e.b)) {
                uf.unite(e.a, e.b);
                ans += e.w;
            }
        }
        return ans;
    }
};