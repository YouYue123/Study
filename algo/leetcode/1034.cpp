#include <bits/stdc++.h>
using namespace std;

// 1034. Coloring A Border [M]
// LeetCode coloring-a-border

struct UF {
    vector<int> parent;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        parent[rootX] = rootY;
    }
    int findRoot (int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
    bool isConnected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
}; 
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(grid);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        UF uf(m * n);
        auto getCode = [&] (int i, int j) {
            return i * n + j;
        };
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int curCode = getCode(i, j);
                for(auto& p : dirs) {
                    int ni = i + p.first, nj = j + p.second;
                    int nCode = getCode(ni, nj);
                    if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if(grid[i][j] == grid[ni][nj] && !uf.isConnected(curCode, nCode)) {
                        // cout << "connect " << i << " " << j << " with " << ni << " " << nj << endl;
                        uf.unite(nCode, curCode);
                    }
                }
            }
        }
        int baseCode = getCode(row, col);
        // cout << uf.isConnected(3, baseCode) << endl;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int curCode = getCode(i, j);
                // if(curCode == baseCode) continue;
                // cout << curCode << endl;
                if(uf.isConnected(curCode, baseCode)) {
                    // cout << "connected: " << i << " " << j << endl;
                    for(auto &p : dirs) {
                        int ni = i + p.first, nj = j +  p.second;
                        int nCode = getCode(ni, nj);
                        if(ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            ans[i][j] = color;
                        } else if(!uf.isConnected(nCode, baseCode)){
                            if(curCode == 4)  cout << "obunder 2" << endl;
                            ans[i][j] = color;
                        }
                    }
                } 
            }
        }
        return ans;
    }
};