#include <bits/stdc++.h>
using namespace std;

// 305. Number of Islands II [H]
// LeetCode number-of-islands-ii

struct UF {
    int cnt = 0;
    vector<int> parent;
    vector<int> rank;
    UF(int m, int n) {
        int size = m * n;
        parent.resize(size);
        rank.assign(size, 1);
        for(int i = 0 ; i < size; i ++) parent[i] = i;
    }

    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        if(rank[rootY] > rank[rootX]) {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        } else{
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        cnt += 1;
    }

    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }

};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UF uf(m, n);
        vector g(m, vector(n, 0));
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int cnt = 0;
        vector<int> ans;
        for(auto& p : positions) {
            int r = p[0], c = p[1];
            if(g[r][c] != 1)  {
                g[r][c] = 1;
                cnt += 1;
                for(auto d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(g[nr][nc] == 0) continue;
                    uf.unite(nr * n + nc, r * n + c);
                }
            }
            ans.push_back(
                cnt - uf.cnt
            );
            // cout << ans.back() << endl;
        }
        return ans;
    }
};