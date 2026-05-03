#include <bits/stdc++.h>
using namespace std;

// 834. Sum of Distances in Tree [H]
// LeetCode sum-of-distances-in-tree

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector size(n, 0);
        vector ans(n, 0);
        auto calc_root = [&] (this auto&& dfs, int cur, int parent) -> void {
            size[cur] = 1;
            for(int nxt : g[cur]) {
                if(nxt == parent) continue;
                dfs(nxt, cur);
                size[cur] += size[nxt];
                ans[cur] += ans[nxt] + size[nxt];
            }
        };
        calc_root(0, -1);
        auto reroot = [&] (this auto&& dfs, int cur, int parent) -> void {
            for(int nxt : g[cur]) {
                if(nxt == parent) continue;
                ans[nxt] = ans[cur] - size[nxt] + (n - size[nxt]);
                dfs(nxt, cur);
            }
        };
        reroot(0, -1);
        return ans;
    }
};