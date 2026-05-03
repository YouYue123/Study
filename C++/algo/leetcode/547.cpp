// 547. Number of Provinces [M]
// LeetCode number-of-provinces

// struct UF {
//     int size;
//     vector<int> parent;
//     vector<int> rank;
//     UF (int n) {
//         size = n;
//         rank.assign(n, 1);
//         parent.resize(n);
//         for(int i = 0; i < n; i ++) parent[i] = i;
//     }
//     void unite(int x, int y) {
//         // cout << x << " " << y << endl;
//         int rootX = findRoot(x);
//         int rootY = findRoot(y);
//         if(rootX == rootY) return;
//         if(rank[rootY] > rank[rootX]) {
//             parent[rootX] = rootY;
//             rank[rootY] += rank[rootX];
//         } else {
//             parent[rootY] = rootX;
//             rank[rootX] += rank[rootY];
//         }
//         size -= 1;
//     }
    
//     int findRoot(int x) {
//         if(parent[x] == x) return x;
//         return parent[x] = findRoot(parent[x]);
//     }

// };
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // UF uf(n);
        // for(int i = 0; i < n; i ++) {
        //     for(int j = 0; j < n; j ++) {
        //         if(isConnected[i][j] == 1) uf.unite(i, j);
        //     }
        // }
        // return uf.size;
        unordered_map<int, vector<int>> g;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(isConnected[i][j] == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector visited(n, false);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(visited[i]) return;
            visited[i] = true;
            for(int nxt : g[i]) dfs(nxt);
        };
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            if(visited[i] ) continue;
            ans += 1;
            dfs(i);
        }
        return ans;
    }
};