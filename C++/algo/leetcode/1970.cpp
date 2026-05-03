// 1970. Last Day Where You Can Still Cross [H]
// LeetCode last-day-where-you-can-still-cross

struct UF {
    vector<int> size;
    vector<int> parent;
    UF(int n): parent(n), size(n, 1) {
        for(int i = 0; i < n; i ++) parent[i] = i;
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
    
    bool connected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
};
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int top = row * col;
        int bottom = row * col + 1;
        UF uf(row * col + 2);
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        vector land(row, vector(col, false));
        for(int day = cells.size() - 1; ; day -= 1) {
            auto& cell = cells[day];
            int r = cell[0] - 1;
            int c = cell[1] - 1;
            int v = r * col + c;
            if(r == 0) uf.unite(v, top);
            if(r == row - 1) uf.unite(v, bottom);
            land[r][c] = true;
            for(auto& d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if(land[nr][nc] == false) continue;
                int nv = nr * col + nc;
                uf.unite(nv, v);
            }
            if(uf.connected(top, bottom)) return day;
        }  
        return -1;      
    }
};