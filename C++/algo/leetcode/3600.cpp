// 3600. Maximize Spanning Tree Stability with Upgrades [H]
// LeetCode maximize-spanning-tree-stability-with-upgrades

struct UF {
    vector<int> parent;
    int cnt;
    vector<int> size;
    UF(int n) {
        this->cnt = n;
        size.assign(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }

    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        } else {
            parent[root_x] = root_y;
            size[root_y] += size[root_x];
        }
        cnt -= 1;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UF must_uf(n);
        UF uf(n);
        int max_s = 0;
        for(auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            max_s = max(max_s, s);
            if(must == 1) {
                if(must_uf.is_connected(u, v)) return -1;
                must_uf.unite(u, v);
            }
            uf.unite(u, v);
        }
        if(uf.cnt != 1) return -1;
        int left = -1, right = max_s * 2 + 1;
        // cout << left << " " << right << endl;
        auto isValid = [&] (int x) {
            UF uf(n);
            for(auto& e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if(must == 1) {
                    if(s < x) return false;
                    uf.unite(u, v);
                } else if(must == 0 && s >= x) {
                    uf.unite(u, v);
                }
            }
            int cnt = 0;
            for(auto& e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if(must == 0 && s < x && s * 2 >= x && cnt < k && !uf.is_connected(u, v)) {
                    cnt += 1;
                    uf.unite(u, v);
                }
            }
            // cout << "x: " << x << " " << uf.cnt << endl;
            return uf.cnt == 1;
        };
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            // cout << mid << endl;
            // cout << isValid(mid) << endl;
            if(isValid(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};