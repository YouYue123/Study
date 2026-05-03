// 2492. Minimum Score of a Path Between Two Cities [M]
// LeetCode minimum-score-of-a-path-between-two-cities

int constexpr INF = 0x3f3f3f3f;
class UF {
private:
    vector<int> parent;
    vector<int> size;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
public:
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    }
    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UF uf(n + 1);
        for(auto& r : roads) {
            int a = r[0], b = r[1];
            // cout << a << " " << b << endl;
            uf.unite(a, b);
        }
        // cout << "unite done" << endl;
        int ans = INF;
        for(auto& r : roads) {
            int a = r[0], b = r[1], d = r[2];
            if(uf.is_connected(1, a) && uf.is_connected(n, a)) {
                ans = min(ans, d);
            }
        }
        return ans;
    }
};