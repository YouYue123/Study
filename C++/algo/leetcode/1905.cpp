// 1905. Count Sub Islands [M]
// LeetCode count-sub-islands

struct UF {
    int size;
    vector<int> parent;
    UF(int size): size(size) {
        parent.resize(size);
        for(int i = 0; i < size; i ++) parent[i] = i;
    }
    void unite (int x, int y) {
        int rootX= findRoot(x);
        int rootY= findRoot(y);
        if(rootX == rootY) return;
        parent[rootX] = rootY;
        size -= 1;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
    bool isConnect(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
};
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int idx = 1;
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, -1}, {0, 1}
        };
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        UF uf(m * n);
        auto getId = [&] (int i, int j) -> int {
            return i * n + j;
        };
        auto dfs1 = [&] (this auto&& dfs1, int i, int j) -> void {
            visited[i][j] = true;
            int curId = getId(i, j);
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                int nId = getId(ni, nj);
                if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if(grid1[ni][nj] == 0 || visited[ni][nj]) continue;
                uf.unite(curId, nId);
                dfs1(ni, nj);
            }
        };
        for(int i = 0; i < m ; i ++) {
            for(int j = 0; j < n; j ++) {
                if(!visited[i][j] && grid1[i][j] != 0) {
                    dfs1(i, j);
                }
            }
        }
        // cout << "constructed uf for grid1" << endl;

        auto dfs2 = [&] (this auto&& dfs2, int i, int j) -> bool {
            visited[i][j] = true;
            int curId = getId(i, j);
            int ans = true;
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                int nId = getId(ni, nj);
                if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if(grid2[ni][nj] == 0 || visited[ni][nj]) continue;
                if(!uf.isConnect(curId, nId)) ans = false;
                ans &= dfs2(ni, nj);
            }
            return ans;
        };
        
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) visited[i][j] = false;
        }

        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(!visited[i][j] && grid2[i][j] == 1 && grid1[i][j] == 1) {
                    // cout << "Checking " << i << " " << j << endl;
                    if(dfs2(i, j)) {
                        // cout << "OK!" << endl;
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};