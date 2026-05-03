// 1391. Check if There is a Valid Path in a Grid [M]
// LeetCode check-if-there-is-a-valid-path-in-a-grid

struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < parent.size(); i ++) parent[i] = i;
        size.resize(n);
        for(int i = 0; i < n; i ++) size[i] = 1;
    }
    void unite(int x, int y) {
        int root_x = findRoot(x);
        int root_y = findRoot(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    }
    int findRoot(int x) {
        // cout << x << endl;
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
    bool isConnect(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, unordered_set<int>> match;
        UF uf(m * n);
        auto getId = [&] (int i, int j) -> int {
            return i * n + j;
        };
        for(int i = 0 ; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                // cout << i << " " << j << endl;
                int curId = getId(i , j);
                if(grid[i][j] == 1) {
                    if(j + 1 < n) {
                        if(grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||  grid[i][j + 1] == 5) {
                            uf.unite(curId, getId(i, j + 1));
                        }
                    }
                } else if(grid[i][j] == 2) {
                    if(i + 1 < m) {
                        if(grid[i + 1][j] == 2 || grid[i+1][j] == 5 ||grid[i + 1][j] == 6) {
                            uf.unite(curId, getId(i + 1, j));
                        }
                    } 
                } else if(grid[i][j] == 3) {
                    if(i + 1 < m) {
                        if(grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6) {
                            uf.unite(curId, getId(i + 1, j));
                        }
                    }
                } else if(grid[i][j] == 4) {
                    if(i + 1 < m) {
                        if(grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6) {
                            uf.unite(curId, getId(i + 1, j));
                        }  
                    }
                    if(j + 1 < n) {
                        if(grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5) {
                            uf.unite(curId, getId(i, j + 1));
                        }
                    }
                } else if(grid[i][j] == 5) {

                } else if(grid[i][j] == 6) {
                    if(j + 1 < n) {
                        if(grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5) {
                            uf.unite(curId, getId(i, j + 1));
                        }
                    }
                }
            }
        }
        return uf.isConnect(0, getId(m - 1, n - 1));
    }
};