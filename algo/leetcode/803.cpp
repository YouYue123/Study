#include <bits/stdc++.h>
using namespace std;

// 803. Bricks Falling When Hit [H]
// LeetCode bricks-falling-when-hit

struct UF {
    vector<int> size;
    vector<int> parent;
    UF(int n): parent(n), size(n, 1) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        if(size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
    int getSize(int x) {
        return size[findRoot(x)];
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int top = m * n;
        UF uf(m * n + 1);
        vector bricks(grid);
        for(auto& h : hits) {
            int r = h[0], c = h[1];
            bricks[r][c] = 0;
        }
        for(int r = 0; r < m; r ++) {
            for(int c = 0; c < n; c ++) {
                if(bricks[r][c] == 0) continue;
                int v = r * n + c;
                if(r == 0) uf.unite(v, top);
                for(auto& d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    int nv = nr * n + nc;
                    if(bricks[nr][nc] == 1) uf.unite(nv, v); 
                }
            }
        }
        vector<int> ans(hits.size(), 0);
        for(int i = hits.size() - 1; i >= 0; i --) {
            auto& h = hits[i];
            int r = h[0], c = h[1];
            int v = r * n + c;
            if(grid[r][c] == 0) continue;
            int oldSize = uf.getSize(top);
            if(r == 0) uf.unite(v, top);
            for(auto& d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int nv = nr * n + nc;
                if(bricks[nr][nc] == 1) uf.unite(nv, v); 
            }
            int newSize = uf.getSize(top);
            bricks[r][c] = 1; 
            ans[i] = max(0, newSize - oldSize - 1);
        }
        return ans;
    }
};