// 1559. Detect Cycles in 2D Grid [M]
// LeetCode detect-cycles-in-2d-grid

struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int total_size) {
        parent.resize(total_size);
        for(int i = 0; i < total_size; i ++) parent[i] = i;
        size.resize(total_size);
        for(int i = 0; i < total_size; i ++) size[i] = 1;
    };
    void unite (int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        } else {
            parent[root_x] = root_y;
            size[root_y] += size[root_x];
        }
    };

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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto uf = UF(m * n);
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}
        };
        auto get_coord = [&] (int x, int y) {
            return x * n + y;
        };
        auto is_valid = [&](int x, int y) {
            if(x < 0 || y < 0 || x >= m || y >= n) return false;
            return true;
        };
        for(int x = 0; x < m; x ++) {
            for(int y = 0; y < n; y ++) {
                int cur_coord = get_coord(x, y);
                for(auto& dir : dirs) { 
                    int n_x = x + dir.first, n_y = y + dir.second;
                    if(!is_valid(n_x, n_y)) continue;
                    if(grid[x][y] == grid[n_x][n_y]) {
                        int n_coord = get_coord(n_x, n_y);
                        if(uf.is_connect(cur_coord, n_coord)) return true;
                        uf.unite(cur_coord, n_coord);
                    }
                }
            }
        }
        return false;
    }
};